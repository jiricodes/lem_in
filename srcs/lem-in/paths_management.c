/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:08:36 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/26 19:42:46 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Enqueue path
*/

t_paths		*append_path(t_paths *head, t_que *path)
{
	t_paths *new;
	t_paths *tmp;

	if (!(new = (t_paths *)ft_memalloc(sizeof(t_paths))))
		error_exit("Malloc at append_path()");
	new->ants = 0;
	new->im_min = 0;
	new->path = path;
	new->next = NULL;
	if (!head)
		return (new);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (head);
}

/*
** Pop first path
*/

t_que		*pop_path(t_paths **all_paths)
{
	t_paths *tmp;
	t_que	*path;

	if (!all_paths || !*all_paths)
		return (NULL);
	tmp = *all_paths;
	*all_paths = (*all_paths)->next;
	path = tmp->path;
	free(tmp);
	return (path);
}

/*
** Parses all paths so that only unique shorthest paths
** remain (they do not share nodes except the start and the end)
*/

static int	path_conflict(t_que *a, t_que *b)
{
	t_que *tmp;

	while (a)
	{
		if (a->node->start || a->node->end)
		{
			a = a->next;
			continue ;
		}
		tmp = b;
		while (tmp)
		{
			if (!(tmp->node->start || tmp->node->end))
			{
				if (ft_strequ(a->node->name, tmp->node->name))
					return (TRUE);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (FALSE);
}

static int	check_uniqueness(t_paths *unique_paths, t_que *path)
{
	t_que *current;

	while (unique_paths)
	{
		current = unique_paths->path;
		if (path_conflict(path, current))
			return (FALSE);
		unique_paths = unique_paths->next;
	}
	return (TRUE);
}

t_paths		*path_parsing(t_paths *all_paths)
{
	t_paths *unique;
	t_que	*current;

	unique = NULL;
	while (all_paths)
	{
		current = pop_path(&all_paths);
		if (check_uniqueness(unique, current))
			unique = append_path(unique, current);
		else
			que_delete(current);
	}
	return (unique);
}
