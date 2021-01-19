/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:35:24 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/19 15:27:10 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void		delete_mode(t_cmd *cmd)
{
	terminal_clear_screen(cmd);
	if (cmd->copy_start != -1)
	{
		cmd->index = cmd->copy_end + 1;
		while ((cmd->index - 1) != cmd->copy_start)
			str_remove(cmd);
		cmd->copy_start = -1;
		cmd->copy_end = -1;
	}
	else
		str_remove(cmd);
	terminal_putstr(cmd);
	update_cursor_on_screen(cmd, 1);
}