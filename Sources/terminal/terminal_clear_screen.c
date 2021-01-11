/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_clear_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:15:23 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/11 12:13:57 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	reset_cursor_pos(t_cmd *cmd)
{
	int		row_num;

	move_cursor_first_col(cmd);
	row_num = (cmd->index - 1) / tgetnum("co");
	while (row_num-- > 0)
		move_cursor_up_line(cmd);
}

void		terminal_clear_screen(t_cmd *cmd)
{
	reset_cursor_pos(cmd);
	tputs(cmd->cap.delete_char.cd, 1, ft_putchar);
}


void		clear_from_till_cursor_end_of_line(t_cmd *cmd)
{
	tputs(cmd->cap.delete_char.cd, 1, ft_putchar);
}
