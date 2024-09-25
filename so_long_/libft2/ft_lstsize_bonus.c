/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:02:18 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/27 14:05:22 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*#include <stdio.h>

void	freelist(t_list *head)
{
	t_list	*tmp;
	while (head)
	{
		tmp = head;
		head =  head->next;
		free(tmp);
	}
}

int main() {

	t_list	*lst = ft_lstnew("Node");
	ft_lstadd_back(&lst, ft_lstnew("Node2"));
	
	int		size = ft_lstsize(lst);
	printf("%d\n", size);
	freelist(lst);
	return (0);
}*/