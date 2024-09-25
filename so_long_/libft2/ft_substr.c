/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:02:38 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/29 22:06:59 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	i;

	i = 0;
	len_s = ft_strlen((char *)s);
	if (!s)
		return (0);
	if (len_s < start)
		return (ft_strdup(""));
	if (len_s < len)
		len = len_s;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && start < len_s)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
int	main()
{
	char	s[] = "Hola";
	size_t	len = 0;
	char *resultado;

    resultado = ft_substr(s, 4294967295, len);
    if (resultado != NULL) {
        printf("%s\n", resultado);
        free(resultado);
	} else {
        printf("Error: ft_substr no pudo crear\n");
    }
	return (0);
}*/
