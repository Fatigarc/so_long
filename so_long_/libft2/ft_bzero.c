/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:51:01 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/09 18:11:34 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
	{
		*p++ = 0;
	}
}

/*
#include <string.h>
int	main()
{
	size_t n;
	char	s[] = {"Salta r"};
	
	n = 2;
	ft_bzero(s, n);
	printf("%s\n", s);
	bzero(s, n)
	printf("%s\n", s);
	return (0);	
}*/
