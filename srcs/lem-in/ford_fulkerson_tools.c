/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:03:22 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 13:20:03 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Returns the solution lenght (amount of lines) for given set of paths
*/

t_paths			*shortest_path(t_paths *paths)
{
	t_paths		*min;

	min = paths;
	while (paths)
	{
		if (get_t_len(paths) < get_t_len(min))
			min = paths;
		paths = paths->next;
	}
	return (min);
}

static t_paths	*longest_path(t_paths *paths)
{
	t_paths		*max;

	max = paths;
	while (paths)
	{
		if (get_t_len(paths) > get_t_len(max))
			max = paths;
		paths = paths->next;
	}
	return (max);
}

static void		reset_ants(t_paths *paths)
{
	while (paths)
	{
		paths->ants = 0;
		paths = paths->next;
	}
}

int				len_solution(t_paths *paths, int ants)
{
	t_paths	*tmp;
	int		len;

	if (!paths)
		return (INT_MAX);
	ants = first_square(paths, ants);
	while (ants > 0)
	{
		tmp = shortest_path(paths);
		tmp->ants += 1;
		ants--;
	}
	len = get_t_len(longest_path(paths));
	reset_ants(paths);
	return (len);
}
