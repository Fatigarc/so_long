/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:58:51 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/26 15:00:18 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_len(char const *s, char delim)
{
	int	i;

	i = 0;
	while (s[i] != delim && s[i])
		i++;
	return (i);
}

static	int	word_count(char const *s, char delim)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != delim)
		{
			count++;
			while (s[i] != delim && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	void	*ft_free_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		w_count;
	char	**result;
	int		i;

	if (!s)
		return (0);
	w_count = word_count(s, c);
	result = (char **)malloc(sizeof (char *) * (w_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = ft_substr(s, 0, word_len(s, c));
			if (!result[i++])
				return (ft_free_str(result));
			s = s + word_len(s, c);
		}
		else
			s++;
	}
	result[w_count] = NULL;
	return (result);
}

/*#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char res[] = "Hola mundo";
	char	c = 'm';
	char	**resul = ft_split(res, c);
	int		i;

	i = 0;
	while (resul[i] != NULL)
	{
		printf("%s\n", resul[i]);
		i++;
	}
	ft_free_str (resul);
	return (0);
}*/