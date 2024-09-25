/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:45:05 by fatigarc          #+#    #+#             */
/*   Updated: 2024/04/27 23:26:59 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
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
		return (&s[ft_strlen(s)]);
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
	while (char_read > 0 && !ft_strchr(stash, NL))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		if (char_read == 0)
			return (free(buf), stash);
		buf[char_read] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(stash), stash = NULL, NULL);
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
	len_stash = ft_strlen(stash);
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
	static char	*stash[MAX_FD];
	char		*line_readed;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = create_stash(stash[fd], fd);
	line_readed = extract_stash(stash[fd]);
	if (!line_readed || line_readed[0] == '\0')
		return (NULL);
	stash[fd] = move_buffer(stash[fd]);
	return (line_readed);
}
