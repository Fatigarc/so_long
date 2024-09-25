/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:13:52 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/16 11:09:48 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*ptr;
	char	*ptr2;
	size_t	i;

	ptr = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (ptr[i] || ptr2[i]))
	{
		if (ptr[i] != ptr2[i])
			return ((unsigned char)ptr[i] - (unsigned char)ptr2[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>

int main()
{
	char *s1 = "abc";
	char *s2 = "abc";
	size_t n;

	n = 7;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
	return (0);
}*/
