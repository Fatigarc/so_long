/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:55:39 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/27 14:07:53 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
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
	t_list	*lst = ft_lstnew("Madrid");
	ft_lstadd_back(&lst, ft_lstnew("42"));
	ft_lstadd_back(&lst, ft_lstnew("ups"));
	t_list	*last_elem = ft_lstlast(lst);
	
	ft_print(last_elem);
	freelist(lst);
	return (0);
}*/