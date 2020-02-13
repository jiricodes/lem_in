/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:42:47 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 15:08:42 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
#define VISUAL_H

# include <mlx.h>
# include "../libs/libft/includes/libft.h"

typedef struct	s_prop
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}				t_prop;

#endif