/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 10:44:06 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	print_list(t_node *head)
{
	int i;

	while (head)
	{
		ft_printf("Elem: %s\n", head->name);
		if (head->start)
			ft_printf("START\n");
		if (head->end)
			ft_printf("END\n");
		i = 0;
		ft_printf("NGB:");
		if (head->ngb != 0)
		{
			while (head->ngb[i])
				ft_printf(" %s", head->ngb[i++]->name);
		}
		ft_printf("\n\n");
		head = head->next;
	}
}

void	print_queue(t_que *queue)
{
	if (!queue)
		return ;
	ft_printf("%s", queue->node->name);
	queue = queue->next;
	while (queue)
	{
		ft_printf(" - %s", queue->node->name);
		queue = queue->next;
	}
	printf("\n");
}

/*
** Print Paths
*/

void	print_paths(t_paths *paths)
{
	int i;

	i = 1;
	while (paths)
	{
		ft_printf("%8d:\t", i);
		print_queue(paths->path);
		paths = paths->next;
		i++;
	}
}
