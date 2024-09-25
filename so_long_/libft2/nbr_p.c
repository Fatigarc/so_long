/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:39:23 by fatigarc          #+#    #+#             */
/*   Updated: 2024/04/28 16:37:34 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_p(uintptr_t n, char *base_values, int base)
{
	int				count;
	unsigned long	nbr;
	unsigned int	base_len;

	nbr = n;
	base_len = base;
	count = 0;
	if (n < (uintptr_t)base)
		return (ft_putchar(base_values[n]));
	else if (n > (uintptr_t)(base_len - 1))
	{
		count = nbr_p(nbr / base_len, base_values, base_len);
		count += nbr_p(nbr % base_len, base_values, base_len);
	}
	return (count);
}
