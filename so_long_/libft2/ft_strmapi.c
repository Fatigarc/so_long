/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:17:03 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/26 16:00:30 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned long	i;
	unsigned long	len_s;

	if (!s || !f)
		return (0);
	len_s = ft_strlen(s);
	ptr = malloc (sizeof (char) * (len_s + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (len_s > i)
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[len_s] = '\0';
	return (ptr);
}
/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
char	ft_toupper_adapted(unsigned int a, char c)
{
	(void)a;
	return (ft_toupper(c));
}

int	main ()
{
	char	s[] = "Paco Yunque";
	char	*m = ft_strmapi(s, ft_toupper_adapted);
	
	printf("%s\n", m);
	free(m);
	return (0);
}*/
