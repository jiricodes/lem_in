/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:14:40 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/01 00:27:26 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	get_minmax_xy(t_prop *xt)
{
	t_node *temp;

	temp = xt->elems;
	xt->max_y = temp->y;
	xt->min_y = temp->y;
	xt->max_x = temp->x;
	xt->min_x = temp->x;
	while (temp->next)
	{
		if (temp->next->y > xt->max_y)
			xt->max_y = temp->next->y;
		if (temp->next->y < xt->min_y)
			xt->min_y = temp->next->y;
		if (temp->next->x > xt->max_x)
			xt->max_x = temp->next->x;
		if (temp->next->x < xt->min_x)
			xt->min_x = temp->next->x;
		temp = temp->next;
	}
}

void	fill_frame(int *img_data, int img_w, int img_h, int color)
{
	int count_h;
	int count_w;

	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
		{
			if (count_w > img_w / 20 && count_h > img_h / 20)
			{
				if (count_w < img_w * 0.95 && count_h < img_h * 0.95)
					img_data[count_h * img_w + count_w] = color;
			}
		}
	}
}

void	fill_rctngl_pattern(int *img_data, int img_w, int img_h)
{
	int count_h;
	int count_w;
	int x;

	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
		{
			x = rand() % (100 + 1 - 0) + 0;
			if (x < 85)
				img_data[count_h * img_w + count_w] = 0xffcc99;
			else
				img_data[count_h * img_w + count_w] = 0xcc9966;
		}
	}
}

void	fill_rctngl(int *img_data, int img_w, int img_h, int color)
{
	int count_h;
	int count_w;

	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
			img_data[count_h * img_w + count_w] = color;
	}
}
