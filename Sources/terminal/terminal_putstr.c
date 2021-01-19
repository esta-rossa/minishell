/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:37:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/19 08:13:37 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

#include <fcntl.h>
#include <stdio.h>

static int	check_border(int i)
{
	int		width;

	width = tgetnum("co");
	if (i == 0)
		return (0);
	if ((i + 1) % width == 0)
		return (1);
	return (0);
}

static void		terminal_putchar(int i, t_cmd *cmd)
{
	if (i >= cmd->copy_start && i <= cmd->copy_end)
	{
		tputs(cmd->cap.display_mode.so, 1, ft_putchar);
		tputs(cmd->cap.display_mode.rv, 1, ft_putchar);
		tputs(cmd->cap.display_mode.hb, 1, ft_putchar);
	}
	else
	{
		tputs(cmd->cap.insert_char.im, 1, ft_putchar);
		tputs(cmd->cap.insert_char.ic, 1, ft_putchar);
	}
	ft_putchar(cmd->line[i]);
	if (i >= cmd->copy_start && i <= cmd->copy_end)
	{
		tputs(cmd->cap.display_mode.me, 1, ft_putchar);
		tputs(cmd->cap.display_mode.se, 1, ft_putchar);
	}
	else
	{
		tputs(cmd->cap.insert_char.ip, 1, ft_putchar);
		tputs(cmd->cap.insert_char.ei, 1, ft_putchar);
	}

}

void			terminal_putstr(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (i < cmd->length)
	{
		terminal_putchar(i, cmd);
		if (check_border(i))
		{
			move_cursor_down_line(cmd);
			move_cursor_first_col(cmd);
		}
		i++;
	}
}