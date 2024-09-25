/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:24:45 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/29 19:24:35 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2));
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, len + 1);
	ft_strlcpy(ret + ft_strlen(s1), s2, len + 1 - ft_strlen(s1));
	return (ret);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	*s1 = "Hola";
	char	*s2 = "Adios";
	
	char	*res = ft_strjoin(s1, s2);
	printf("%s\n", res);
	free(res);
	return (0);
}*/