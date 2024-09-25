/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:31 by fatigarc          #+#    #+#             */
/*   Updated: 2024/03/04 12:17:35 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	cdest = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (len-- > 0)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len-- > 0)
		{
			cdest[len] = csrc[len];
		}
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
    char    src[] = "\0\0 1234";
    //char  dest[] = "\0\0 1234";
    char    dest[0];
    size_t  len;
    len = 4;
    printf("%s", ft_memmove(dest, src + 3, len));
    printf("%s", memmove(dest, src + 3, len));
    return (0);
}*/
