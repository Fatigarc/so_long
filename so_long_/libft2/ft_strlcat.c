/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:48:49 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/13 17:45:39 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	j;

	j = 0;
	len_dst = ft_strlen(dst);
	if (dstsize > len_dst)
	{
		while ((j + len_dst + 1) < dstsize && src[j] != '\0')
		{
			dst[len_dst + j] = src[j];
			j++;
		}
		dst[len_dst + j] = '\0';
		return (len_dst + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}

/*int	main (void)
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	dest[14] = "rrrrrrrrrrrrrr";
	size_t	destsize;

	destsize = 15;

	size_t	copied = ft_strlcat(dest, src, destsize);
	printf("%s\n", dest);
	printf("%zu\n", copied);

	char	src1[] = "lorem ipsum dolor sit amet";
	char	dest1[14] = "rrrrrrrrrrrrrr";
	size_t	cop = strlcat(dest1, src1, destsize);
	printf("%s\n", dest1);
	printf("%zu\n", cop);
	return (0);
}*/
