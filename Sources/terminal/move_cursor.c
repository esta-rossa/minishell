/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:41:45 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 09:49:48 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void		move_cursor_first_col(t_cmd *cmd)
{
	tputs(cmd->cap.cursor.cr, 1, ft_putchar);
}

void		move_cursor_up_line(t_cmd *cmd)
{
	tputs(cmd->cap.cursor.up, 1, ft_putchar);
}

void		move_cursor_last_col(t_cmd *cmd)
{
	int		index;
	int		width;

	width = tgetnum("co");
	index = 0;
	move_cursor_first_col(cmd);
	while (index < width)
	{
		tputs(cmd->cap.cursor.ri, 1, ft_putchar);
		index++;
	}
}

void		move_cursor_down_line(t_cmd *cmd)
{
	tputs(cmd->cap.cursor.dw, 1, ft_putchar);
}
