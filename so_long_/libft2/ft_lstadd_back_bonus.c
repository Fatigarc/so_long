/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:09:22 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/27 14:34:29 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
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

int	main()
{
	t_list	*lst = NULL;
	t_list	*new = ft_lstnew("Cantar");
	ft_lstadd_back(&lst, new);
	ft_print(lst);
	
	t_list	*lst = ft_lstnew("Cantar");
	t_list	*lst2 = ft_lstnew("gritar");
	ft_lstadd_back(&lst, new);
	ft_print(lst);
	
	freelist(lst);
	return (0);
}*/
