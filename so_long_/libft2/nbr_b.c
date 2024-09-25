/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:33:10 by fatigarc          #+#    #+#             */
/*   Updated: 2024/04/26 17:12:51 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_b(long n, char *base_values, int base)
{
	int	count;

	if (n < 0)
	{
		ft_putchar('-');
		return (nbr_b(-n, base_values, base) + 1);
	}
	else if (n < base)
		return (ft_putchar(base_values[n]));
	else
	{
		count = nbr_b(n / base, base_values, base);
		return (count += nbr_b(n % base, base_values, base));
	}
}
