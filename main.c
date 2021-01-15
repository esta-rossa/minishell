/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:12:18 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/15 14:29:23 by ikhadem          ###   ########.fr       */
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
	cmd->buff_size = CMD_MAX_LEN;
	memset(cmd->line, '\0', cmd->buff_size);
	return (TRUE);
}

void	shift_handler(int arrow)
{
	if (arrow == K_SHIFT_UP)
		dprintf(open("/dev/ttys003", O_RDWR), "SHIFT UP\n");
	else if (arrow == K_SHIFT_DOWN)
		dprintf(open("/dev/ttys003", O_RDWR), "SHIFT DOWN\n");
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
	read(STDIN_FILENO, &c, sizeof(int));
	if (isprint(c))
		insert_mode(c, command);
	else if (c == K_RETURN)
		delete_mode(command);
	else if (c == K_LEFT)
		move_index_left(command);
	else if (c == K_RIGHT)
		move_index_right(command);
	else if (c == K_SHIFT_DOWN || c == K_SHIFT_UP)
		shift_handler(c);
	else if (c == K_CNTL_UP || c == K_CNTL_DOWN ||
				c == K_CNTL_LEFT || c == K_CNTL_RIGHT)
		contorle_handeler(c, command);
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