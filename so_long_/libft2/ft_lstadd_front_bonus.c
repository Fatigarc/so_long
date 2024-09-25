/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:19:53 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/29 22:04:22 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *lst;
	}
	*lst = new;
}

/*#include <stdio.h>

void	ft_print(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
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

int main() {

	t_list	*node1 = ft_lstnew("nodo 1");
	t_list	*node2 = ft_lstnew("nodo 2");

	ft_lstadd_front(&node1, node2);
	ft_print(node1);
	freelist(node1);
	return (0);
}*/