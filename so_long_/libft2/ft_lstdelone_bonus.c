/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:41:39 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/27 15:14:45 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}

/*#include <stdlib.h>
#include <stdio.h>

void	ft_print(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

void freelist(t_list *head) 
{
    t_list *tmp;

    while (head != NULL) 
	{
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int	main ()
{	
	char	*str = ft_strdup("info Node 1");
	char	*str1 = ft_strdup("Info Node 2");
	char	*str2 = ft_strdup("Info Node 3");

	t_list	*node = ft_lstnew(str); 
	t_list	*node1 = ft_lstnew(str1);
	t_list	*node2 = ft_lstnew(str2);
	
	ft_lstadd_back(&node, node1);
	ft_lstadd_back(&node, node2);

	printf("Antes\n");
	ft_print(node);
	
	printf("Después\n");
	ft_lstdelone(node1, free);
	ft_print(node);
	freelist(node);
	return (0);
}*/
