/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:10:41 by fatigarc          #+#    #+#             */
/*   Updated: 2024/08/23 08:59:27 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef NL
#  define NL '\n'
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen1(char *s);
char	*ft_strjoin1(char *s1, char *s2);
char	*create_stash(char *stash, int fd);
char	*extract_stash(char *stash);
char	*move_buffer(char *str);
char	*ft_strchr1(char *s, int c);
void	ft_strlcpy1(char *dst, const char *src, size_t dstsize);
size_t	position_nl(char *str);

#endif
