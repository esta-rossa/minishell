/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:37:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 10:49:12 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

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

static void		terminal_putchar(int c, t_capability cap)
{
	tputs(cap.insert_char.ic, 1, ft_putchar);
	ft_putchar(c);
	tputs(cap.insert_char.ip, 1, ft_putchar);
}

void			terminal_putstr(t_cmd *cmd)
{
	int		i;

	i = 0;
	tputs(cmd->cap.insert_char.im, 1, ft_putchar);
	while (i < cmd->length)
	{
		terminal_putchar(cmd->line[i], cmd->cap);
		if (check_border(i))
		{
			move_cursor_down_line(cmd);
			move_cursor_first_col(cmd);
		}
		i++;
	}
	tputs(cmd->cap.insert_char.ei, 1, ft_putchar);
}