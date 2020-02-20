/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:03:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/20 16:32:35 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Creates the output string
*/

static void	move_one(t_prop *xt, t_que *tmp, char **out)
{
	int		cnt;
	char	*new;

	new = NULL;
	cnt = 0;
	// print_queue(tmp);
	while (tmp)
	{
		new = str_append(out[cnt + tmp->shift], xt->ant_cnt, tmp->node->name);
		free(out[cnt + tmp->shift]);
		out[cnt + tmp->shift] = ft_strdup(new);
		free(new);
		tmp->shift += 1;
		tmp = tmp->next;
		cnt++;
	}
	xt->ant_cnt += 1;
}

void		move_ants(t_prop *xt, t_paths *paths)
{
	char	**out;
	int		len;
	t_que	*tmp;
	t_paths	*head;

	if (!paths)
		return ;
	len = get_n_strings(paths);
	out = (char **)ft_memalloc(len * sizeof(char *));
	if (!out)
		error_exit("Malloc at move_ants");
	head = paths;
	// print_paths(paths);
	while (xt->ant_cnt <= xt->f_ants)
	{
		if (paths->ants)
		{
			move_one(xt, paths->path->next, out);
			paths->ants--;
		}
		paths = paths->next;
		if (!paths)
			paths = head;
	}
	print_colony(xt);
	print_output(out);
}
