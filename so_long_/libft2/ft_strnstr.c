/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:26:59 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/16 20:07:55 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		len_needle;
	size_t		len_haystack;
	const char	*match_start;

	match_start = 0;
	len_haystack = ft_strlen(haystack);
	len_needle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	if (len > len_haystack)
		len = len_haystack;
	while (len >= len_needle)
	{
		if (ft_strncmp(haystack, needle, len_needle) == 0)
		{
			match_start = haystack;
			return ((char *)match_start);
		}
		len --;
		haystack++;
	}
	return (0);
}

/*#include <string.h>

int	main() 
{
	char    m[] = "Aqui, todo bien en el cluster";
	char    n[] = "todo";
	size_t	len = 10;
	char    *r = ft_strnstr(m, n, len);
	char	*p = strnstr(m, n, len);
	
	printf("%s\n", r);
	printf("%s\n", p);
	return (0);
}*/
