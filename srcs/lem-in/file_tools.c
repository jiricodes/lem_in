/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:00:06 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/29 20:39:44 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	open_graph_file(t_prop *xt, char *filename)
{
	FILE = open(filename, O_RDONLY);
	if (DEBUG)
		ft_printf("Processed File (%d): %s\n", FILE, filename);
	if (FILE < 0)
		error_exit("Failed to open given file");
}

void	close_graph_file(t_prop *xt)
{
	if (close(FILE) < 0)
		error_exit("Failed to close given graph file");
}
