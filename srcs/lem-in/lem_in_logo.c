/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_logo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:04:07 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 15:10:59 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_logo(void)
{
	PRT("{BLUE}{B} __\n");
	PRT("||||\n");
	PRT("||||\n");
	PRT("||||	 |||///// ||\\     /||      |||  ||\\    |||\n");
	PRT("||||	 |||      |||\\   /|||      |||  |||\\   |||\n");
	PRT("||||     |||      |||\\\\ //|||      ");
	PRT("|||  |||\\\\  |||\n");
	PRT("||||     ||||||   ||| \\|/ ||| //// |||  ||| \\\\ |||\n");
	PRT("||||     |||      |||     |||      |||  |||  \\\\|||\n");
	PRT("\\\\\\\\\\\\\\\\\\\\||      |||     |||      |||  |||   \\|||\n");
	PRT(" \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ |||     |||      |||  |||    \\||");
	PRT("{EOC}\n\n");
}