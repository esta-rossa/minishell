/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:50:07 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/13 08:17:46 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void		reset_cursor_pos1(t_cmd *cmd)
{
	int		row_num;

	row_num = cmd->length / tgetnum("co");
	while (row_num > 0)
	{
		move_cursor_up_line(cmd);
		row_num--;
	}
	move_cursor_first_col(cmd);
}

static void		reset_cursor_pos2(t_cmd *cmd, int mode)
{
	int		row_num;

	row_num = (cmd->index - mode - 1) / tgetnum("co");
	move_cursor_first_col(cmd);
	while (row_num > 0)
	{
		move_cursor_up_line(cmd);
		row_num--;
	}
}

void		update_cursor_on_screen(t_cmd *cmd, int mode)
{
	int		row_num;
	int		col_num;

	row_num = (cmd->index - 1) / tgetnum("co");
	col_num = (cmd->index - 1) % tgetnum("co");
	if (mode == 1)
		reset_cursor_pos1(cmd);
	else if (mode == 2)
		reset_cursor_pos2(cmd, 1);
	else if (mode == 3)
		reset_cursor_pos2(cmd, -1);
	while (row_num > 0)
	{
		move_cursor_down_line(cmd);
		row_num--;
	}
	while (col_num > 0)
	{
		tputs(cmd->cap.cursor.ri, 1, ft_putchar);
		col_num--;
	}
}
