/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:32:31 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/13 14:49:23 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != '\0')
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*#include <string.h>
int	main(void)
{
	char	src[] = "lorem";
	char	dest[15];
	size_t	destsize;

	destsize = 15;
	size_t	copied = ft_strlcpy(dest, src, destsize);
	printf("%zu\n", copied);
	size_t	cop = strlcpy(dest, src, destsize);
	printf("%zu\n", cop);
	return (0);
}*/
