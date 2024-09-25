/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:32:31 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/21 13:07:28 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) < 0)
			return (-2147483648);
		return (6);
	}
	while (*str != '\0')
	{
		if (ft_putchar(*str) < 0)
			return (-2147483648);
		i++;
		str++;
	}
	return (i);
}
