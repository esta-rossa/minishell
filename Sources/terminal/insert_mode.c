/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:16:48 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 15:30:58 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <fcntl.h>
#include <stdio.h>

void			insert_mode(int c, t_cmd *cmd)
{
	terminal_clear_screen(cmd);
	str_add(cmd, c);
	dprintf(open("/dev/ttys002", O_RDWR), "index: %i\nlength: %i\nLine: %s\n",
					cmd->index, cmd->length, cmd->line);
	terminal_putstr(cmd);
}