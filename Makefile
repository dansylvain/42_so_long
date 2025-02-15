# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dan <dan@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 05:50:42 by dsylvain          #+#    #+#              #
#    Updated: 2025/02/15 19:01:36 by dan              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS =  -g #-Wall -Wextra -Werror

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFT = libft/libft.a

FT_PRINTF = ft_printf/libftprintf.a

GET_NEXT_LINE = get_next_line/get_next_line.a

SRC =	src/main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		src/utils.c \
		src/map_validation/check_map_is_valid.c \
		src/map_validation/check_map_is_valid_2.c \
		src/map_validation/check_map_is_valid_utils.c \
		src/map_validation/check_elements_are_reachable.c \
		src/map_validation/check_elements_are_reachable_2.c \
		src/map_validation/dfs_map_element.c \
		src/structs_initialization/init_data_structs.c \
		src/structs_initialization/init_data_structs_2.c \
		src/structs_initialization/init_data_structs_utils.c \
		src/free_data.c \
		src/display_win.c \
		src/move_funcs.c \
		src/hooks.c \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME) -Llibft -lft -Lft_printf -lftprintf
	@echo "\033[0;32mCompilation successful\033[0m"

$(LIBFT):
	@make -s -C libft 

$(FT_PRINTF):
	@make -s -C ft_printf 

$(GET_NEXT_LINE):
	@make -s -C get_next_line 
	
mlx_linux/libmlx.a:
	@make -s -C mlx_linux

%.o: %.c
	@printf "%-80s" $<
	@{ $(CC) $(CFLAGS) -Ilibft -I/usr/include -Imlx_linux -O3 -c $< -o $@; } 2>&1 || \
		(echo ""; echo "\033[0;31mCompilation of $< failed\033[0m"; exit 1)
	@echo "\033[0;32mcompiled\033[0m"

clean:
	@rm	-f	$(OBJ) $(OBJ_BONUS)
	@make -s -C libft clean 
	@make -s -C ft_printf clean 
	@make -s -C get_next_line clean 


fclean: clean
	@rm	-f	$(NAME) $(NAME_BONUS)
	@make -s -C libft fclean
	@make -s -C ft_printf fclean 
	@make -s -C get_next_line fclean 

re:	fclean	all	

.PHONY: all clean fclean re bonus
