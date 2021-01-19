/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:39:50 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/19 14:49:56 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINES_H
# define FT_DEFINES_H

# ifndef TRUE
#  define TRUE 0
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define MATH_MIN(a, b) (a > b ? b : a)
# define MATH_MAX(a, b) (a > b ? a : b)

# define K_EXIT 28

# define K_RETURN 127
# define K_CARRIAGE_RETURN 10
# define K_UP 4283163
# define K_DOWN 4348699
# define K_RIGHT 4414235
# define K_LEFT 4479771
# define K_HOME 4741915
# define K_END 4610843

# define K_ALT_UP 16691
# define K_ALT_DOWN 16947
# define K_ALT_RIGHT 1130044187
# define K_ALT_LEFT 1146821403
# define K_ALT_C 42947
# define K_ALT_X 8948194
# define K_ALT_V 10127586

# define K_CNTL_RIGHT 17205
# define K_CNTL_LEFT 17461
# define K_CNTL_UP 16693
# define K_CNTL_DOWN 16949
# define K_CNTL_C 3

/*
**	im ==> string to inter insert mode
**	ic ==> string to insert char
**	ip ==> string to output char padding if needed
**	ei ==> string to exit insert mode
*/

typedef	struct	s_ichar
{
	char		*im;
	char		*ic;
	char		*ip;
	char		*ei;
}				t_ichar;

/*
**	dm ==> string to inter delete mode
**	dc ==> string to delete char
**	ed ==> string to exit delete mode
** cd ==> string to delete from cursor till end of display
*/

typedef	struct	s_dchar
{
	char		*dc;
	char		*dm;
	char		*ed;
	char		*cd;
}				t_dchar;

/*
**	cm ==> string to move the cursor to pos(l, c)
**	le ==> string to move cursor left
**	nd ==> string to move cursor right
**	ho ==> string to move cursor to home pos
**	up ==> string to move up one row
**	dw ==> string to move down one row (beware if wrapping exists)
*/

typedef struct	s_cmotion
{
	char		*le;
	char		*up;
	char		*ri;
	char		*dw;
	char		*cr;
	char		*PC;
}				t_cmotion;

typedef struct	s_display_mode
{
	char		*so;
	char		*se;
	char		*me;
	char		*rv;
	char		*hb;
}				t_display_mode;

typedef	struct	s_capability
{
	t_ichar			insert_char;
	t_dchar			delete_char;
	t_cmotion		cursor;
	t_display_mode	display_mode;
}				t_capability;

typedef	struct	s_cmd
{
	char			*line;
	int				index;
	int				length;
	int				buff_size;
	int				copy_start;
	int				copy_end;
	char			*clip_board;
	t_capability	cap;
}				t_cmd;

#endif