/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capabilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:31:34 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 09:51:04 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void		init_edit_char(t_cmd *cmd)
{
	cmd->cap.insert_char.im = tgetstr("im", NULL);
	cmd->cap.insert_char.ei = tgetstr("ei", NULL);
	cmd->cap.insert_char.ic = tgetstr("ic", NULL);
	cmd->cap.insert_char.ip = tgetstr("ip", NULL);
}

static void		init_delete_char(t_cmd *cmd)
{
	cmd->cap.delete_char.dc = tgetstr("dc", NULL);
	cmd->cap.delete_char.dm = tgetstr("dm", NULL);
	cmd->cap.delete_char.ed = tgetstr("ed", NULL);
	cmd->cap.delete_char.cd = tgetstr("cd", NULL);
}

static void		init_cursor(t_cmd *cmd)
{
	cmd->cap.cursor.le = tgetstr("le", NULL);
	cmd->cap.cursor.ri = tgetstr("nd", NULL);
	cmd->cap.cursor.up = tgetstr("up", NULL);
	cmd->cap.cursor.dw = tgetstr("do", NULL);
	cmd->cap.cursor.cr = tgetstr("cr", NULL);
	cmd->cap.cursor.PC = tgets
}

void			ft_init_capabilities(t_cmd *cmd)
{
	init_edit_char(cmd);
	init_delete_char(cmd);
	init_cursor(cmd);
}
