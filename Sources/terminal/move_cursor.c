/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:42:31 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 17:01:29 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void		move_cursor_right(t_cmd *cmd)
{
	if (cmd->index - 1 == cmd->length)
		return;
	cmd->index++;
	tputs(cmd->cap.cursor.ri, 1, ft_putchar);
}

void		move_cursor_left(t_cmd *cmd)
{
	if (cmd->index == 1)
		return;
	cmd->index--;
	tputs(cmd->cap.cursor.le, 1, ft_putchar);
}

void		update_cursor_on_screen(t_cmd *cmd)
{
	int		index;

	index = 1;
	move_cursor_first_col(cmd);
	while (index < cmd->index)
	{
		tputs(cmd->cap.cursor.ri, 1, ft_putchar);
		index++;
	}
}