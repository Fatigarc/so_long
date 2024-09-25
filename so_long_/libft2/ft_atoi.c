/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:18:19 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/09 18:11:39 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	number;

	number = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
		{
			sign = -1;
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (sign * number);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main ()
{
	char	str[] = "-+469 \n";
	printf("Convierto %s en %d\n", str, ft_atoi(str));
	char	str1[] = "-+469 \n";
	printf("Convierto %s en %d\n", str1, atoi(str1));
	return (0);
}*/
