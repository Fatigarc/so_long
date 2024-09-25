/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:21:45 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/18 06:36:24 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*ptr;
	size_t	i;

	i = 0;
	len_s1 = (ft_strlen(s1) + 1);
	ptr = (char *)malloc((len_s1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len_s1)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

/*#include <string.h>

int	main()
{
	char *original = "coucou";
    char *copy = strdup(original);
	char *ft_copy = ft_strdup(original);

	printf("%s\n", ft_copy);
	printf("%s\n", copy);
	free(copy);
	free(ft_copy);
	return (0);
}*/
