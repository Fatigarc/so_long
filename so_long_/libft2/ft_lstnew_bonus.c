/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:26:45 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/29 22:06:27 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	data = 36;
	t_list	*node = ft_lstnew(&data);

	if (node == NULL)
	{
		printf("not possible to create the new node \n");
		return (1);
	}
	else
	{
		printf("%d\n", *(int *)(node->content));
		free(node);
		return (0);
	}
}*/
