/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:39:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/24 18:30:50 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Create node
*/

t_node	*create_node(char *name, int x, int y)
{
	t_node	*node;

	node = (t_node *)ft_memalloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->name = name;
	node->x = x;
	node->y = y;
	node->ngb = NULL;
	node->cap = NULL;
	node->empty = 1;
	return (node);
}

/*
** Deletes node
*/

void	delete_node(t_node *node)
{
	int i;

	i = 0;
	if (!node)
		return ;
	if (node->ngb != NULL)
	{
		while (node->ngb[i])
			node->ngb[i++] = NULL;
		free(node->ngb);
		i = 0;
		free(node->cap);
	}
	free(node);
}

/*
** Deletes the whole list
*/

void	delete_list(t_node *lst)
{
	t_node *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		delete_node(tmp);
	}
}

/*
** Creates node at the begining of given list and returns a pointer to it
*/

t_node	*create_front(t_node *head, char *name, int x, int y)
{
	t_node *node;

	node = create_node(name, x, y);
	return (add_front(head, node));
}

/*
** Creates a node at the back of given list and returns pointer to the head
*/

t_node	*create_back(t_node *head, char *name, int x, int y)
{
	t_node *node;

	node = create_node(name, x, y);
	return (add_back(head, node));
}
