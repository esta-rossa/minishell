/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:12:18 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/19 15:23:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <signal.h>
#include <termios.h>
#include <string.h>
#include "termcaps.h"
#include "ft_defines.h"

#include <fcntl.h>
#include <stdio.h>

struct termios term;

int		ft_init_command(t_cmd *cmd)
{
	if (!(cmd->line = (char *)malloc(CMD_MAX_LEN * sizeof (char))))
		return (FALSE);
	cmd->index = 1;
	cmd->length = 0;
	cmd->copy_start = -1;
	cmd->copy_end = -1;
	cmd->buff_size = CMD_MAX_LEN;
	memset(cmd->line, '\0', cmd->buff_size);
	return (TRUE);
}

void	alt_handler(int arrow, t_cmd *cmd)
{
	if (arrow == K_ALT_UP)
		dprintf(open("/dev/ttys002", O_RDWR), "ALT UP\n");
	else if (arrow == K_ALT_DOWN)
		dprintf(open("/dev/ttys002", O_RDWR), "ALT DOWN\n");
	else if (arrow == K_ALT_RIGHT)
	{
		if (cmd->index - 1 == cmd->length)
			return;
		if (cmd->index - 1 == cmd->copy_start)
		{
			cmd->copy_start++;
			cmd->index++;
			if (cmd->copy_start == cmd->copy_end)
			{
				cmd->copy_start = -1;
				cmd->copy_end = -1;
			}
		}
		else
		{
			if (cmd->copy_start == -1)
				cmd->copy_start = cmd->index - 1;
			cmd->copy_end = cmd->index;
			cmd->index++;
		}
		copy_insert_mode(cmd);
	}
	else if (arrow == K_ALT_LEFT)
	{
		if (cmd->index  == 1)
			return;
		if (cmd->index - 1 == cmd->copy_end)
		{
			cmd->copy_end--;
			cmd->index--;
			if (cmd->copy_end == cmd->copy_start)
			{
				cmd->copy_start = -1;
				cmd->copy_end = -1;
			}
		}
		else
		{
			if (cmd->copy_end == -1)
			cmd->copy_end = cmd->index - 1;
			cmd->copy_start = cmd->index - 2;
			cmd->index--;
		}
		copy_insert_mode(cmd);
	}
	else if (arrow == K_ALT_C)
	{
		if (cmd->clip_board)
			free(cmd->clip_board);
		cmd->clip_board = (char *)malloc(sizeof(char) * (cmd->copy_end - cmd->copy_start + 1));
		bzero(cmd->clip_board, cmd->copy_end - cmd->copy_start + 1);
		strncpy(cmd->clip_board, cmd->line + cmd->copy_start, cmd->copy_end - cmd->copy_start);
		dprintf(open("/dev/ttys003", O_RDWR), "Copied: %s\n", cmd->clip_board);
	}
	else if (arrow == K_ALT_X)
	{
		if (cmd->clip_board)
			free(cmd->clip_board);
		cmd->clip_board = (char *)malloc(sizeof(char) * (cmd->copy_end - cmd->copy_start + 1));
		bzero(cmd->clip_board, cmd->copy_end - cmd->copy_start + 1);
		strncpy(cmd->clip_board, cmd->line + cmd->copy_start, cmd->copy_end - cmd->copy_start);
		if (cmd->copy_start != -1)
		{
			cmd->index = cmd->copy_end + 2;
			while ((cmd->index - 2) != cmd->copy_start)
				str_remove(cmd);
			str_remove(cmd);
			cmd->copy_start = -1;
			cmd->copy_end = -1;
		}
		copy_insert_mode(cmd);
		dprintf(open("/dev/ttys003", O_RDWR), "Cutted: %s\n", cmd->clip_board);
	}
	else if (arrow == K_ALT_V)
	{
		int		i = 0;
		while (cmd->clip_board[i] != '\0')
		{
			str_add(cmd, cmd->clip_board[i]);
			i++;
		}
		copy_insert_mode(cmd);
		dprintf(open("/dev/ttys003", O_RDWR), "Pasted: %s\n", cmd->clip_board);
	}
}

void	contorle_handeler(int arrow, t_cmd *cmd)
{
	int		counter;

	counter = 0;
	if (arrow == K_CNTL_UP)
		dprintf(open("/dev/ttys002", O_RDWR), "CNTL UP\n");
	else if (arrow == K_CNTL_DOWN)
		dprintf(open("/dev/ttys002", O_RDWR), "CNTL DOWN\n");
	else if (arrow == K_CNTL_LEFT)
	{
		while(cmd->line[cmd->index - 2] == ' ' && cmd->index != 1)
			move_index_left(cmd);
		while (cmd->line[cmd->index - 2] != ' ' && cmd->index != 1)
			move_index_left(cmd);
	}
	else if (arrow == K_CNTL_RIGHT)
	{
		while (cmd->line[cmd->index - 1] != ' ' && cmd->index - 1 != cmd->length)
			move_index_right(cmd);
		while(cmd->line[cmd->index - 1] == ' ' && cmd->index != 1)
			move_index_right(cmd);
	}
}

void input_manip(t_cmd *command)
{
	int			c;

	c = 0;
	read(STDIN_FILENO, &c, sizeof(c));
	if (isprint(c))
		insert_mode(c, command);
	else if (c == K_RETURN)
		delete_mode(command);
	else if (c == K_LEFT)
		move_index_left(command);
	else if (c == K_RIGHT)
		move_index_right(command);
	else if (c == K_ALT_DOWN || c == K_ALT_UP ||
				c == K_ALT_LEFT || c == K_ALT_RIGHT ||
				c == K_ALT_C || c == K_ALT_X || c == K_ALT_V)
		alt_handler(c, command);
	else if (c == K_CNTL_UP || c == K_CNTL_DOWN ||
				c == K_CNTL_LEFT || c == K_CNTL_RIGHT)
		contorle_handeler(c, command);
	else if (c == K_HOME)
		move_index_home(command);
	else if (c == K_END)
		move_index_end(command);
	else if (c == K_EXIT)
	{
		unset_terminal(&term);
		exit(-1);
	}
	else
		dprintf(open("/dev/ttys003", O_RDWR), "%d\n", c);
	dprintf(open("/dev/ttys003", O_RDWR), "%d, %d + %d$\n",
				command->index,
				command->copy_start,
				command->copy_end);
}

int		main(int argc, char **argv, char **env)
{
	t_cmd		command;
	if (!init_terminal())
		exit(-1);
	if (!setup_terminal(&term))
		exit(-1);
	if (!ft_init_command(&command))
		exit(-1);
	ft_init_capabilities(&command);
	while (1)
		input_manip(&command);
	if (!unset_terminal(&term))
		exit(-1);
	return 0;
}