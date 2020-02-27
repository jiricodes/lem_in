/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:42:47 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:25:18 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H

# define IMGS xt->imgs
# define IMG_PTR xt->img_ptr
# define MLX_PTR xt->mlx_ptr
# define IMG_DAT xt->img_data
# define WIN_PTR xt->win_ptr
# define TRUE 1
# define FALSE 0
# define CAPACITY 1
# define FF_ALL 1
# define W_W 1920
# define W_H 1080
# define FRAMES 120
# define THREADS 5
# define W_NAME "VISU-HEXX"

# include <pthread.h>
# include <mlx.h>
# include "../libs/libft/includes/libft.h"

typedef struct		s_img
{
	void			*bg;
	int				*bgdat;

	void			*sand;
	int				*sanddat;

	void			*room;
	int				*roomdat;
	int				roomsize;

	void			*uniroom;
	int				*uniroomdat;

	void			*start;
	int				*startdat;

	void			*end;
	int				*enddat;

	void			*line;
	int				*linedat;

	void			*path;
	int				*pathdat;

	void			*ant;
	int				*antdat;

	int				disp_names;
	int				disp_all;
	int				disp_path;
	int				disp_80s;
	int				pause;
}					t_img;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				nx;
	int				ny;
	int				start;
	int				end;
	struct s_node	**ngb;
	struct s_node	*next;
	struct s_node	*path;
	int				*cap;
	int				empty;
	int				visited;

}					t_node;

typedef struct		s_paths
{
	t_node			*node;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_lines
{
	char			*str;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_ant
{
	int				cnt;
	double			x;
	double			y;
	int				dx;
	int				dy;
	double			stpx;
	double			stpy;
	t_node			*curpos;
	t_node			*nextpos;
	int				error;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_prop
{
	int				f_ants;
	int				f_start;
	int				f_end;
	int				n_ants;
	int				n_start;
	int				n_end;
	int				n_rooms;
	int				n_links;
	t_paths			*all_paths;
	t_lines			*lines;
	t_ant			*ants;
	char			**moves;

	t_node			*elems;
	t_img			*imgs;

	void			*mlx_ptr;
	void			*win_ptr;

	int				max_y;
	int				min_y;
	int				max_x;
	int				min_x;
	int				x_coef;
	int				y_coef;

	int				dx;
	int				dy;
	int				stpx;
	int				stpy;
	int				color;
	int				fd;
}					t_prop;

typedef struct		s_pcur
{
	int				x;
	int				y;
}					t_pcur;

/*
** Nodes Management
*/

t_node				*create_node(char *name, int x, int y);
void				delete_node(t_node *node);
void				delete_list(t_node *lst);
t_node				*create_front(t_node *head, char *name, int x, int y);
t_node				*create_back(t_node *head, char *name, int x, int y);
t_node				*add_front(t_node *head, t_node *node);
t_node				*add_back(t_node *head, t_node *node);
t_node				*find_node(t_node *head, char *name);
int					add_neighbor(t_prop *xt, t_node *node, t_node *neighbor);
int					count_neighbors(t_node **neighbors);
t_node				*find_start(t_node *list);
t_node				*find_end(t_node *list);
void				reset_visits(t_node *list);
void				capacitize_ngbs(t_node *list);

/*
** Queue Management
*/

t_paths				*path_parsing(t_paths *all_paths);

/*
** Breath First Search for paths
*/

void				delete_paths(t_paths *all_paths);

/*
** Ford-Fulkerson max flow algorithm
*/

int					ford_fulkerson(t_node *graph, t_paths **all_paths,\
						int ants);
void				get_flow_paths(t_node *start, t_node *end,\
						t_paths **all_paths);
int					len_solution(t_paths *paths, int ants);
void				new_solution(t_paths **storage, t_paths **new);
int					get_t_len(t_paths *paths);

/*
**	Print Functions NEEDS TO CHANGE TO FT_PRINTF!!!
*/

void				print_list(t_node *head);
void				print_paths(t_paths *paths);
void				print_ant_data(t_prop *xt);
void				print_graph(t_node *graph);
void				print_edges(t_node *head);

void				error_exit(char *msg);

/*
** Input functions
*/

void				read_input(t_prop *xt);
void				save_line(t_prop *xt, char *line);
int					get_coord(char *str);

/*
** Images Create
*/
int					get_cor_x(int coord, t_prop *xt);
int					get_cor_y(int coord, t_prop *xt);
void				get_minmax_xy(t_prop *xt);
void				fill_frame(int *img_data, int img_w, int img_h, int color);
void				fill_rectangle_pattern(int *img_data, int img_w,\
						int img_h, int color, int color_2);
void				fill_rectangle(int *img_data, int img_w, int img_h,\
						int color);
void				create_background(t_prop *xt);
void				create_room(t_prop *xt);
void				create_start(t_prop *xt);
void				create_end(t_prop *xt);
void				create_sand(t_prop *xt);
void				create_lines(t_prop *xt);
void				create_path(t_prop *xt);
void				create_ant(t_prop *xt);

/*
** Images Draw
*/
void				*draw_ant_algo(t_ant *ant);
void				draw_farm(t_prop *xt);
void				redraw(t_prop *xt);
void				connect_nodes(int *image, t_prop *xt,\
						t_node *beg, t_node *end);

/*
** Controls
*/

int					key_hook_press(int keycode, t_prop *xt);
void				print_paths(t_paths *paths);
void				create_ant_list(t_prop *xt);
void				update_ant_positions(t_prop *xt, char *line);
void				move_ants(t_prop *xt);
void				modify_ant_location(t_prop *xt);
void				recalc_ant_movement(t_prop *xt);
void				create_path_list(t_prop *xt, t_lines *lines);
void				clear_split(char **props);
void				display_stats(t_prop *xt);

#endif