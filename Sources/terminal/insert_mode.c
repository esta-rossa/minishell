/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:16:48 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 09:27:56 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void			insert_mode(int c, t_cmd *cmd)
{
	str_add(cmd, c);
	terminal_clear_screen(cmd);
	terminal_putstr(cmd);
}