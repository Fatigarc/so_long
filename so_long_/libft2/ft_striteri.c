/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:00:33 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/26 16:42:00 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>
#include <string.h>


void	ft_putchar(unsigned int i, char *c)
{
	(void)i;
	printf("%c", *c);
}
int	main()
{
	char	str[] = "Hola Mundo";

	ft_striteri(str, ft_putchar);
	return (0);	
}*/