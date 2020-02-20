/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:59:07 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/20 16:32:37 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_len(t_que *list)
{
	int cnt;

	cnt = 0;
	while (list)
	{
		cnt += 1;
		list = list->next;
	}
	return (cnt);
}

int		get_t_len(t_paths *paths)
{
	int total;

	total = 0;
	total += get_len(paths->path);
	total += paths->ants;
	return (total);
}

void	get_min_path(t_paths *paths)
{
	int		min;
	t_paths	*head;

	min = get_t_len(paths);
	paths->im_min = 1;
	head = paths;
	while (paths->next)
	{
		if (get_t_len(paths->next) < min)
		{
			paths->next->im_min = 1;
			head->im_min = 0;
			head = paths->next;
			min = get_t_len(head);
		}
		paths = paths->next;
	}
}

void	several(int ants, t_paths *paths)
{
	t_paths *head;

	head = paths;
	while (ants > 0)
	{
		paths = head;
		get_min_path(paths);
		while (paths)
		{
			if (paths->im_min == 1)
			{
				paths->ants += 1;
				ants -= 1;
				paths->im_min = 0;
				break ;
			}
			paths = paths->next;
		}
	}
}

void	assign_ants(t_prop *xt)
{
	if (xt->all_paths->next)
		several(xt->f_ants, xt->all_paths);
	else
		xt->all_paths->ants = xt->f_ants;
	// print_paths(xt->all_paths);
	move_ants(xt, xt->all_paths);
}
