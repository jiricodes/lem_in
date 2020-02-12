/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/12 11:11:15 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define NAME xt->elems->name
#include "../includes/lem_in.h"

int		count_elems(char **array)
{
	int cnt;

	cnt = 0;
	while (array[cnt] != 0)
		cnt++;
	return (cnt);
}

int		is_number(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (!ft_isdigit(str[cnt]))
			return (0);
		cnt++;
	}
	return (1);
}

int		is_ants(char *str, t_prop *xt)
{
	if (is_number(str) == 1)
		return (1);
	return (0);
}

/*
** check_link
*/

int		is_link(char *line, t_prop *xt)
{
	int		cnt;
	char	**props;

	props = ft_strsplit(line, '-');
	if (count_elems(props) != 2)
		return (0);
	return (1);
}

/*
** check_room
*/

int		is_room(char *line, t_prop *xt)
{
	char	**props;

	props = ft_strsplit(line, ' ');
	if (count_elems(props) != 3)
		return (0);
	if (is_number(props[1]) && is_number(props[2]))
		return (1);
	else
		return (0);
}

/*
** prepend node
*/

void	prepend_node(char **props, t_prop *xt)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->name = props[0];
	new->x = ft_atoi(props[1]);
	new->y = ft_atoi(props[2]);
	new->visited = 0;
	new->ngb = 0;
	if (xt->f_start == 1)
	{
		new->start = 1;
		xt->f_start = 0;
	}
	if (xt->f_end == 1)
	{
		new->end = 1;
		xt->f_end = 0;
	}
	new->next = xt->elems;
	xt->elems = new;
}

/*
** saves new room/ call prepend
*/

void	save_room(char *line, t_prop *xt)
{
	char **props;

	props = ft_strsplit(line, ' ');
	if (xt->elems == 0)
	{
		xt->elems = (t_node *)malloc(sizeof(t_node));
		xt->elems->visited = 0;
		xt->elems->ngb = 0;
		xt->elems->name = props[0];
		xt->elems->x = ft_atoi(props[1]);
		xt->elems->y = ft_atoi(props[2]);
		xt->elems->next = NULL;
		if (xt->f_start == 1)
		{
			xt->elems->start = 1;
			xt->f_start = 0;
		}
		if (xt->f_end == 1)
		{
			xt->elems->start = 1;
			xt->f_end = 0;
		}
		xt->elems->ngb = NULL;
	}
	else
		prepend_node(props, xt);
}

/*
** saves link: kudos Jiri
*/

void	save_link(char *line, t_prop *xt)
{
	char	**props;
	char	*match;
	t_node	*node1;
	t_node	*node2;

	match = 0;
	props = ft_strsplit(line, '-');
	node1 = find_node(xt->elems, props[0]);
	node2 = find_node(xt->elems, props[1]);
	if (node1 == 0 || node2 == 0)
	{
		ft_putstr("Nothing found, suka\n");
		exit(0);
	}
	add_neighbor(node1, node2);
	add_neighbor(node2, node1);
}

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
	t_paths *all_paths;

	all_paths = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
			save_commands(line, xt);
		else if (is_ants(line, xt) == 1)
			save_ants(line, xt);
		else if (is_room(line, xt) == 1)
			save_room(line, xt);
		else if (is_link(line, xt) == 1)
			save_link(line, xt);
		else
			error_exit("Wrong input, bitch");
	}
	check_input(xt);
	//print_list(xt->elems);
	bfs(find_start(xt->elems), find_end(xt->elems), &all_paths);
	assign_ants(xt, all_paths);
	delete_list(xt->elems);
	delete_paths(all_paths);
}
