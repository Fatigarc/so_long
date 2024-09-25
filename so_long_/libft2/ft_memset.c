/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:07:24 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/16 19:56:19 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len-- > 0)
		*p++ = c;
	return (b);
}

/*#include <string.h>

int	main()
{
	char	b[10] = "Nadar a";
	size_t	len;

	len	= 3;
	ft_memset(b, '-', len);
	printf("%s\n", b);
	memset(b, '-', len);
	printf("%s\n", b);
	return (0);
}*/
