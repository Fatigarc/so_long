/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:48:29 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/20 16:09:26 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verify_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	if (*set || *s1)
	{
		while (ft_verify_is_set(s1[start], set))
			start++;
		while (start < end && ft_verify_is_set(s1[end - 1], set))
			end--;
		p = ft_substr(s1, start, end - start);
		if (!p)
			return (NULL);
		return (p);
	}
	return (ft_strdup(""));
}

/*#include <stdio.h>

int	main()
{
	char	*s1 = "oh Window oh";
	char	*set = "oh";
	char	*p = ft_strtrim(s1, set);
	
	printf("%s\n", p);
	free(p);
	return (0);
}*/