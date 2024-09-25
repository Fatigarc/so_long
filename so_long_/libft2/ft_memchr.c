/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:55:20 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/12 18:55:05 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}

/*#include <string.h>

int	main()
{
	int		c;
	size_t	n;
	char	s[] = "Caral";

	c = 'a';
	n = 4;
	printf("%p\n", ft_memchr(s, c, n));	
	printf("%s\n", s);
	printf("%p\n", memchr(s, c, n));
	printf("%s\n", s);
	return (0);
}*/
