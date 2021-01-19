/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:16:48 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/18 12:12:22 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void			insert_mode(int c, t_cmd *cmd)
{
	terminal_clear_screen(cmd);
	str_add(cmd, c);
	terminal_putstr(cmd);
	update_cursor_on_screen(cmd, 1);
}

void			copy_insert_mode(t_cmd *cmd)
{
	terminal_clear_screen(cmd);
	terminal_putstr(cmd);
	update_cursor_on_screen(cmd, 1);
}