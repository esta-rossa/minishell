/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:42:31 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/19 14:53:56 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

#include <fcntl.h>
#include <stdio.h>

void		move_index_right(t_cmd *cmd)
{
	if (cmd->copy_start != -1)
	{
		cmd->index = cmd->copy_end;
		cmd->copy_start = -1;
		cmd->copy_end = -1;
	}
	if (cmd->index - 1 >= cmd->length)
		return;
	cmd->index++;
	copy_insert_mode(cmd);
}

void		move_index_left(t_cmd *cmd)
{
	if (cmd->copy_start != -1)
	{
		cmd->index = cmd->copy_start + 2;
		cmd->copy_start = -1;
		cmd->copy_end = -1;
	}
	if (cmd->index == 1)
		return;
	cmd->index--;
	copy_insert_mode(cmd);
}

void		move_index_home(t_cmd *cmd)
{
	int		row_num;

	cmd->copy_start = -1;
	cmd->copy_end = -1;
	copy_insert_mode(cmd);
	row_num = (cmd->index - 1) / tgetnum("co");
	move_cursor_first_col(cmd);
	while (row_num-- > 0)
		move_cursor_up_line(cmd);
	cmd->index = 1;
}

void		move_index_end(t_cmd *cmd)
{
	cmd->copy_start = -1;
	cmd->copy_end = -1;
	copy_insert_mode(cmd);
	move_index_home(cmd);
	while (cmd->index <= cmd->length)
		move_index_right(cmd);
}