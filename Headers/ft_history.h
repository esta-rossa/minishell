/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:27:26 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/13 09:42:42 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_H
# define FT_HISTORY_H

# ifndef HISTORY_LIMIT
#  define HISTORY_LIMIT 1000
# endif

# include "termcaps.h"

typedef struct	s_history
{
	int					index;
	char				*line;
	struct s_history	*previous;
	struct s_history	*next;
}				t_history;

#endif