/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:41:29 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/26 10:52:30 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			i;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	s[]	= "Hello";
	char	dst[3];

	printf("%s\n", ft_memcpy(dst, s, 3));

	char	dst1[3];
	printf("%s\n", memcpy(dst1, s, 3));
	return (0);	
}*/
