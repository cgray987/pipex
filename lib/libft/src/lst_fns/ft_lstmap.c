/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:08:37 by cgray             #+#    #+#             */
/*   Updated: 2023/10/31 15:23:20 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates the list 'lst' and applies given function 'f'
 on content of each node.
Creates new list from successive use of 'f'.
the 'del' function is used to delete content of node
if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*element;
	void	*set;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		set = f(lst->content);
		element = ft_lstnew(set);
		if (!element)
		{
			del(set);
			ft_lstclear(&new_lst, (*del));
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, element);
		lst = lst->next;
	}
	return (new_lst);
}
