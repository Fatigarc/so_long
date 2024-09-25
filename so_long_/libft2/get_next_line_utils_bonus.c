/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:44:42 by fatigarc          #+#    #+#             */
/*   Updated: 2024/04/27 23:30:45 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return ;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ret)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(ret, s1, len_s1 + len_s2 + 1);
	ft_strlcpy(ret + ft_strlen(s1), s2, len_s2 + 1);
	free(s1);
	return (ret);
}

size_t	position_nl(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0' || !str)
		return (0);
	while (str[i] && str[i] != NL)
		i++;
	if (str[i] == NL)
		i++;
	return (i);
}

char	*move_buffer(char *str)
{
	size_t	j;
	size_t	i;
	char	*temp;

	i = 0;
	if (!*str)
		return (NULL);
	j = position_nl(str);
	temp = (char *)malloc(sizeof(char) + 1 * (ft_strlen(str) - j));
	if (!temp)
		return (NULL);
	while (str[j] != '\0')
		temp[i++] = str[j++];
	temp[i] = '\0';
	if (!*temp)
		return (free(str), free(temp), NULL);
	free (str);
	return (temp);
}
