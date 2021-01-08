/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:35:24 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 15:30:20 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <fcntl.h>
#include <stdio.h>

void		delete_mode(t_cmd *cmd)
{
	terminal_clear_screen(cmd);
	str_remove(cmd);
	dprintf(open("/dev/ttys002", O_RDWR), "index: %i\nlength: %i\nLine: %s\n",
		cmd->index, cmd->length, cmd->line);
	terminal_putstr(cmd);
}