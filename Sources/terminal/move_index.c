/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:42:31 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/15 17:20:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

#include <fcntl.h>
#include <stdio.h>

void		move_index_right(t_cmd *cmd)
{
	if (cmd->index - 1 == cmd->length)
		return;
	cmd->index++;
	update_cursor_on_screen(cmd, 2);
}

void		move_index_left(t_cmd *cmd)
{
	if (cmd->index == 1)
		return;
	cmd->index--;
	update_cursor_on_screen(cmd, 3);
}

void		move_index_home(t_cmd *cmd)
{
	int		row_num;

	row_num = (cmd->index - 1) / tgetnum("co");
	move_cursor_first_col(cmd);
	while (row_num-- > 0)
		move_cursor_up_line(cmd);
	cmd->index = 1;
}

void		move_index_end(t_cmd *cmd)
{
	move_index_home(cmd);
	while (cmd->index <= cmd->length)
		move_index_right(cmd);
}