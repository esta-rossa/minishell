/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:15:03 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 18:05:11 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flip_bit(int *data, int bit)
{
	if (and_op(*data, bit))
		bit_off(*data, bit);
	else
		bit_on(*data, bit);
}
