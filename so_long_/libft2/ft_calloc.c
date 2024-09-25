/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:15:16 by fatigarc          #+#    #+#             */
/*   Updated: 2024/07/12 17:05:34 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
/*#include <stdio.h>

int	main ()
{
	size_t	count = 5;
	size_t	size = 6;
	
	char *str = ft_calloc(count, size);
	printf("%p\n", str);
	free(str);
	return (0);
}*/
