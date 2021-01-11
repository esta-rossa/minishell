/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:28:00 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/11 12:24:21 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/errno.h>
# include <ncurses.h>
# include <term.h>
# include "ft_io.h"
# include "ft_defines.h"
# include "ft_string.h"

int			init_terminal(void);
int			setup_terminal(struct termios *term);
int			unset_terminal(struct termios *term);
void		ft_init_capabilities(t_cmd *cmd);
void		insert_mode(int c, t_cmd *cmd);
void		terminal_putstr(t_cmd *cmd);
void		delete_mode(t_cmd *cmd);
void		terminal_clear_screen(t_cmd *cmd);
void		move_cursor_first_col(t_cmd *cmd);
void		move_cursor_up_line(t_cmd *cmd);
void		move_cursor_last_col(t_cmd *cmd);
void		move_cursor_down_line(t_cmd *cmd);
void		update_cursor_on_screen(t_cmd *cmd, int mode);
void		move_index_left(t_cmd *cmd);
void		move_index_right(t_cmd *cmd);

#endif