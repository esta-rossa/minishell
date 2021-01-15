/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 08:02:52 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/13 09:42:06 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# ifndef CMD_MAX_LEN
#  define CMD_MAX_LEN 100
# endif

# include <string.h>
# include "termcaps.h"
# include "ft_defines.h"

void			str_add(t_cmd *cmd, int c);
void			str_remove(t_cmd *cmd);

#endif