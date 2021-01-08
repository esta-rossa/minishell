/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_clear_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:15:23 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 09:33:06 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static int	check_border(int i)
{
	int		width;

	width = tgetnum("co");
	if (i == 0)
		return (0);
	if (i % width == 0)
		return (1);
	return (0);
}

void		terminal_clear_screen(t_cmd *cmd)
{
	int		index;
	int		border_check;

	index = cmd->length - 1;
	tputs(cmd->cap.delete_char.dm, 1, ft_putchar);
	while (index > 0)
	{
		border_check = check_border(index);
		if (border_check == 0)
			tputs(cmd->cap.cursor.le, 1, ft_putchar);
		else
		{
			move_cursor_last_col(cmd);
			move_cursor_up_line(cmd);
		}
		tputs(cmd->cap.delete_char.dc, 1, ft_putchar);
		index--;
	}
	tputs(cmd->cap.delete_char.ed, 1, ft_putchar);
}

void		clear_from_till_cursor_end_of_line(t_cmd *cmd)
{
	tputs(cmd->cap.delete_char.cd, 1, ft_putchar);
}
