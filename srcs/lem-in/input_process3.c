/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/20 16:31:19 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** turns start/end flags and keeps count of occurences
*/

void	save_commands(char *str, t_prop *xt)
{
	if (ft_strequ(str, "##start") == 1)
	{
		xt->f_start = 1;
		xt->n_start += 1;
	}
	if (ft_strequ(str, "##end") == 1)
	{
		xt->f_end = 1;
		xt->n_end += 1;
	}
}

void	save_ants(char *str, t_prop *xt)
{
	xt->f_ants = ft_atoi(str);
	xt->n_ants += 1;
}

/*
** reads commands, rooms and links, cuts out crap and launches compliance check
*/

void	read_input(t_prop *xt)
{
	char	*line;
	int		maxflow;

	xt->all_paths = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' || line[0] == 'L')
			save_commands(line, xt);
		else if (is_ants(line, xt) == 1)
			save_ants(line, xt);
		else if (is_room(line, xt) == 1)
			save_room(line, xt);
		else if (is_link(line, xt) == 1)
			save_link(line, xt);
		else
			error_exit("Wrong Input");
		free(line);
	}
	check_input(xt);
	// print_graph(xt->elems);
	maxflow = ford_fulkerson(xt->elems, &(xt->all_paths), xt->f_ants);
	// bfs(find_start(xt->elems), find_end(xt->elems), &(xt->all_paths));
	// print_paths(xt->all_paths);
	// ft_printf("Max Flow: %d\n", maxflow);
	// ft_printf("Flow Paths:\n");
	// print_paths(xt->all_paths);
	// xt->all_paths = path_parsing(xt->all_paths);
}

/*
** Checks if given string containes valid coordinate, and returns it as int.
*/

int		get_coord(char *str)
{
	long	nb;

	nb = ft_latoi(str);
	if (nb > INT_MAX || nb < INT_MIN)
		error_exit("Coordinates out of int range");
	return ((int)nb);
}
