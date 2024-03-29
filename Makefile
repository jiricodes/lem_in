# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 10:53:16 by asolopov          #+#    #+#              #
#    Updated: 2020/03/03 14:03:19 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3 -Wall -Wextra -Werror
GREEN		=	\033[0;32m
GREENB		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[0;31m

# LEM-IN files

NAME				= lem-in

LEM_IN_SRCS			= main.c \
					input_process2.c \
					input_process3.c \
					print_functions.c \
					print_functions2.c \
					nodes_management.c \
					nodes_management2.c \
					nodes_management3.c \
					nodes_management4.c \
					nodes_management5.c \
					input_check.c \
					input_check2.c \
					bfs_functions.c \
					clear_memory.c \
					queue_functions.c \
					queue_functions2.c \
					paths_management.c \
					exit_functions.c \
					moving_ants.c \
					moving_ants_tools.c \
					assigning_ants.c \
					ford_fulkerson.c \
					ford_fulkerson_tools.c \
					ford_fulkerson_tools2.c \
					ford_fulkerson_tools3.c \
					flow_paths.c \
					read_input.c \
					new_input_process.c \
					new_input_process2.c \
					file_tools.c \
					flag_tools.c \
					lem_in_logo.c 

LEM_IN_FILES		= $(addprefix $(LEM_IN_DIR), $(LEM_IN_SRCS))

# VISU-HEXX files

VISU_HEXX			= visu-hexx

VISU_HEXX_SRCS		= controls.c\
					create_ant_nodes.c\
					clear_mem.c\
					clear_mem_ops.c\
					exit_functions.c\
					img_tools.c\
					img_tools2.c\
					img_create_ant.c\
					img_create_back.c\
					img_create_lines.c\
					img_create_rooms.c\
					img_display_obj.c\
					img_display_opt.c\
					img_draw_ants.c\
					img_draw_lines.c\
					img_draw_all.c\
					input_process.c\
					input_identify.c\
					input_save.c\
					legend.c\
					lines_management.c\
					main.c\
					move_ants.c\
					nodes_management.c\
					nodes_management2.c\
					nodes_find.c\
					paths_receive.c\
					paths_tools.c\
					flags_out.c\
					input_check.c\
					update_ant_position.c \
					

VISU_HEXX_FILES		= $(addprefix $(VISU_HEXX_DIR), $(VISU_HEXX_SRCS))

# Time Files

TIME_SRCS			= ft_start_timer.c \
					ft_stop_timer.c \
					ft_time_lapsed.c \
					ft_markdown.c \
					ft_stopwatch_init.c \
					ft_clear_marks.c \
					ft_stopwatch_del.c


TIME_FILES		= $(addprefix $(TIME_DIR), $(TIME_SRCS))
# Directories

LEM_IN_DIR			= ./srcs/lem-in/
VISU_HEXX_DIR		= ./srcs/visu-hexx/
TIME_DIR			= ./srcs/time/
LIBFT_DIR			= ./libs/libft/
LIB_MLX_DIR			= ./libs/libmlx

# Libraries

LIBFT_NAME			= libft.a
MLX_NAME			= libmlx.a
MLX_A				= $(addprefix $(LIB_MLX_DIR), $(MLX_NAME))
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBMLXFLAGS			= -I$(LIB_MLX_DIR) -L$(LIB_MLX_DIR) -lmlx -framework OpenGL -framework Appkit

# Includes
INCLUDES			= includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(VISU_HEXX)
	@echo "$(RED)Compiling lem_in...$(RES)"
	@gcc -o $(NAME) $(CFLAGS) -I $(INCLUDES) $(LEM_IN_FILES) $(TIME_FILES) $(LIBFT_A)
	@echo "$(GREENB)$(NAME) $(GREEN)done.$(RES)"

$(VISU_HEXX) : $(LIBFT_NAME)
	@echo "$(RED)Compiling visu-hexx...$(RES)"
	@gcc -o $(VISU_HEXX) $(CFLAGS) -I $(INCLUDES) $(LIBFT_A) $(VISU_HEXX_FILES) $(LIBMLXFLAGS) -lpthread
	@echo "$(GREENB)$(VISU_HEXX) $(GREEN)done.$(RES)"

$(LIBFT_NAME):
	@echo "$(RED)Compiling Libft Library$(RES)"
	@Make all -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"
	@echo "$(RED)Compiling MLX Library$(RES)"
	@Make all -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

clean:
	@echo "$(RED)Removing Object Files...$(RES)"
	@Make clean -C $(LIBFT_DIR)
	@Make clean -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

fclean: clean
	@echo "$(RED)Removing Executables & Library...$(RES)"
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(VISU_HEXX)
	@/bin/rm -f $(CHECKER_EXE)
	@Make fclean -C $(LIBFT_DIR)
	@Make fclean -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

re: fclean all