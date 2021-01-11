/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:42:31 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/11 12:22:35 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

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
	update_cursor_on_screen(cmd, 2);
}
