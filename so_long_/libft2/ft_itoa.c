/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:27:15 by fatigarc          #+#    #+#             */
/*   Updated: 2024/07/12 17:05:30 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	size;
	long	num;

	num = n;
	size = count_n(n);
	if (n < 0)
	{
		num = num * -1;
		size++;
	}
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[size] = '\0';
	while (size--)
	{
		ptr[size] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

/*#include <stdio.h>

int	main()
{
	int	n = -2147483648;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
