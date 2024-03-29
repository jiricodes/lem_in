/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stopwatch_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:58:00 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 12:46:02 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time_code.h"

t_tstamp	*ft_stopwatch_init(void)
{
	t_tstamp *new;

	new = (t_tstamp *)ft_memalloc(sizeof(t_tstamp));
	if (!new)
		return (NULL);
	new->start = 0;
	new->marks = NULL;
	new->end = 0;
	return (new);
}
