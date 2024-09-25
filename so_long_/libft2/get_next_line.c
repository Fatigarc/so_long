/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:10:44 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 08:27:47 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr1(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[ft_strlen1(s)]);
	return (0);
}

char	*create_stash(char *stash, int fd)
{
	char		*buf;
	ssize_t		char_read;

	char_read = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (char_read > 0 && !ft_strchr1(stash, NL))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			return (free(buf), free(stash), stash = NULL, NULL);
		}
		if (char_read == 0)
			return (free(buf), stash);
		buf[char_read] = '\0';
		stash = ft_strjoin1(stash, buf);
		if (!stash)
			return (free(buf), free(stash), stash = NULL, NULL);
	}
	return (free(buf), buf = NULL, stash);
}

char	*extract_stash(char *stash)
{
	char	*buf;
	size_t	len_stash;
	int		i;
	int		k;

	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	k = 0;
	i = 0;
	len_stash = ft_strlen1(stash);
	buf = (char *)malloc(sizeof(char) * (len_stash + 1));
	if (!buf)
		return (NULL);
	while (stash[i] && stash[i] != NL)
		buf[k++] = stash[i++];
	if (stash[i] == NL)
		buf[k++] = NL;
	buf[k] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line_readed;
	char		*line_created;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line_readed, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line_created = create_stash(stash, fd);
	line_readed = extract_stash(line_created);
	if (!line_readed || line_readed[0] == '\0')
		return (free(line_created), free (stash), NULL);
	stash = move_buffer(line_created);
	return (line_readed);
}
