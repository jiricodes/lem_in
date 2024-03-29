/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:28:17 by solopov           #+#    #+#             */
/*   Updated: 2020/03/02 11:42:21 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static void	free_strings(char *one, char *two, char *three)
{
	free(one);
	free(two);
	free(three);
}

static void	display_ants_rooms_links(t_prop *xt)
{
	char *main;
	char *num;
	char *out;

	main = ft_strdup("Total number of rooms: ");
	num = ft_itoa(xt->n_rooms);
	out = ft_strjoin(main, num);
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 10, 0xffffff, out);
	free_strings(main, num, out);
	main = ft_strdup("Total number of ants: ");
	num = ft_itoa(xt->f_ants);
	out = ft_strjoin(main, num);
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 25, 0xffffff, out);
	free_strings(main, num, out);
	main = ft_strdup("Total number of links: ");
	num = ft_itoa(xt->n_links / 2);
	out = ft_strjoin(main, num);
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 40, 0xffffff, out);
	free_strings(main, num, out);
}

static void	display_path_str(t_prop *xt)
{
	char	*main;
	char	*num;
	char	*out;
	t_paths *temp;
	int		cnt;

	cnt = 0;
	temp = xt->all_paths;
	while (temp)
	{
		cnt += 1;
		temp = temp->next;
	}
	main = ft_strdup("Total number of paths: ");
	num = ft_itoa(cnt);
	out = ft_strjoin(main, num);
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 55, 0xffffff, out);
	free_strings(main, num, out);
}

static void	display_controls(t_prop *xt)
{
	char *str;

	str = ft_strdup("1: display all links");
	mlx_string_put(MLX_PTR, WIN_PTR, W_W - 500, 10, 0xffffff, str);
	free(str);
	str = ft_strdup("2: display paths");
	mlx_string_put(MLX_PTR, WIN_PTR, W_W - 500, 25, 0xffffff, str);
	free(str);
	str = ft_strdup("3: display paths on black bg");
	mlx_string_put(MLX_PTR, WIN_PTR, W_W - 500, 40, 0xffffff, str);
	free(str);
	str = ft_strdup("N: show room/ant numbers");
	mlx_string_put(MLX_PTR, WIN_PTR, W_W - 500, 55, 0xffffff, str);
	free(str);
	str = ft_strdup("SPACE: play/ pause");
	mlx_string_put(MLX_PTR, WIN_PTR, W_W - 500, 70, 0xffffff, str);
	free(str);
	str = ft_strdup("RIGHT ARROW: move forward one step");
	mlx_string_put(MLX_PTR, WIN_PTR, W_W - 500, 85, 0xffffff, str);
	free(str);
	str = ft_strdup("R: restart visualiser");
	mlx_string_put(MLX_PTR, WIN_PTR, W_W - 500, 100, 0xffffff, str);
	free(str);
}

void		display_stats(t_prop *xt)
{
	display_ants_rooms_links(xt);
	display_controls(xt);
	display_controls_add(xt);
	display_path_str(xt);
}
