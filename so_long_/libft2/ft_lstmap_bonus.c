/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:15:07 by fatigarc          #+#    #+#             */
/*   Updated: 2024/02/09 20:02:20 by fatigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*new_node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&lst_new, (*del));
			return (lst_new);
		}
		ft_lstadd_back(&lst_new, new_node);
		lst = lst->next;
	}
	return (lst_new);
}

/*#include <stdio.h>
#include <stdlib.h>

void *transform_content(void *content)
{
    char *str = (char *)content;
    char *result = ft_strdup(str);
    for (size_t i =  0; result[i]; i++) {
        result[i] = ft_toupper(result[i]);
    }
    return result;
}

void free_content(void *content)
{
    free(content);
}

int	main()
{
	char	*str = "Universe";
	char	*str2 = "Swimmers";
	
	t_list	*lst = ft_lstnew(str);
	ft_lstadd_back(&lst, ft_lstnew(str2));
	t_list	*new_lst = ft_lstmap(lst, transform_content, free_content);
	t_list	*current = new_lst;
	
	if (!new_lst)
	{
		printf("Error: it is null");
		return (1);
	}
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/