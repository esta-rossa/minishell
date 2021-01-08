/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:33:52 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/08 08:51:44 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_IO_H
# define ft_IO_H

# include <unistd.h>
# include "ft_defines.h"

int		ft_putchar_fd(int fd, int c);
int		ft_putstr_fd(int fd, char *str);
int		ft_putchar(int c);
int		ft_print_error(char *str);

#endif