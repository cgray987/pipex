/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:58:10 by cgray             #+#    #+#             */
/*   Updated: 2023/12/06 14:01:24 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*-------------------------------------------*/
/*Returns last node of the list 'list'
*/
t_list_gnl	*ft_list_last(t_list_gnl *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/*Adds the node 'buf' at the end of the list 'list'
*/
void	ft_list_add_back(t_list_gnl **list, char *buf)
{
	t_list_gnl	*new_node;
	t_list_gnl	*last_node;

	last_node = ft_list_last(*list);
	new_node = malloc(sizeof(t_list_gnl));
	if (!new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
	}
	else
		last_node->next = new_node;
	new_node->string_buffer = buf;
	new_node->next = NULL;
}

/* frees memory for buf and 'clear node' used in fn 'scoot line forward'
*/
void	list_free(t_list_gnl **list, t_list_gnl *clear_node, char *buf)
{
	t_list_gnl	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->string_buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clear_node && clear_node->string_buffer[0])
		*list = clear_node;
	else
	{
		free(buf);
		free(clear_node);
	}
}

/* Function moves pointer to last line past the '\n' char found previously
in list and frees memory
*/
void	scoot_line_forward(t_list_gnl **list)
{
	t_list_gnl	*last_node;
	t_list_gnl	*clear_node;
	char		*buf;
	int			node_i;
	int			buf_i;

	buf = malloc(BUFFER_SIZE + 1);
	clear_node = malloc(sizeof(t_list_gnl));
	if (buf == NULL || clear_node == NULL)
		return ;
	last_node = (ft_list_last(*list));
	node_i = 0;
	buf_i = 0;
	while (last_node->string_buffer[node_i]
		&& last_node->string_buffer[node_i] != '\n')
		++node_i;
	while (last_node->string_buffer[node_i]
		&& last_node->string_buffer[++node_i])
	{
		buf[buf_i++] = last_node->string_buffer[node_i];
	}
	buf[buf_i] = '\0';
	clear_node->string_buffer = buf;
	clear_node->next = NULL;
	list_free(list, clear_node, buf);
}

/* Follow '\n' list logic and copy last line of list to string 'str'
*/
void	copy_list_to_string(t_list_gnl *list, char *str)
{
	int	node_i;
	int	j;

	j = 0;
	while (list)
	{
		node_i = 0;
		while (list->string_buffer[node_i])
		{
			if (list->string_buffer[node_i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->string_buffer[node_i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

/*------------------------------------------------------------------*/
