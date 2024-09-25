/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:09:30 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/09 16:53:26 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)-> content);
	free(*lst);
	*lst = NULL;
}

/*#include <stdlib.h>

void	delete_content(void *content)
{
	free(content);
}
int	main()
{
	char	*str1;
	char	*str2;
	
	str1 = malloc(sizeof(char) * 6);
	str2 = malloc(sizeof(char) * 3);
	
	ft_strlcpy(str1, "hurry", 6);
	ft_strlcpy(str2, "up", 3);
	t_list	*lst = ft_lstnew(str1);
	t_list	*lst2 = ft_lstnew(str2);
	
	lst->next = lst2;
	printf("%s\n", lst->content);
	printf("%s\n", lst2->content);

	ft_lstclear(&lst, delete_content);
	printf("%s\n", lst->content);
}*/