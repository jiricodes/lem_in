/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ant_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:09:09 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/01 00:14:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static t_ant	*new_ant_node(t_node *start, int nb)
{
	t_ant	*new;

	new = (t_ant *)malloc(sizeof(t_ant));
	new->cnt = nb;
	new->curpos = start;
	new->nextpos = 0;
	new->x = start->nx;
	new->y = start->ny;
	new->next = 0;
	new->nextpos = 0;
	new->error = 0;
	return (new);
}

static void		append_ant_node(t_prop *xt, t_node *start, int nb)
{
	t_ant *temp;

	temp = xt->ants;
	while (temp->next)
		temp = temp->next;
	temp->next = new_ant_node(start, nb);
}

void			create_ant_list(t_prop *xt)
{
	t_node	*start;
	int		cnt;

	cnt = 1;
	start = find_start(xt->elems);
	xt->ants = new_ant_node(start, cnt);
	while (++cnt <= xt->f_ants)
		append_ant_node(xt, start, cnt);
	update_ant_positions(xt, xt->lines->str);
}
