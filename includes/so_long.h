/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:59:03 by dan               #+#    #+#             */
/*   Updated: 2024/01/16 04:33:18 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "paths.h"

# define SPRITES_NUM 73	

typedef struct s_game_data	t_game_data;

typedef enum t_type
{
	empty,
	wall,
	collectible,
	exit_door,
	position
}	t_type;

typedef enum e_keycode
{
	KEY_LEFT	= 65361,
	KEY_UP		= 65362,
	KEY_RIGHT	= 65363,
	KEY_DOWN	= 65364,
	KEY_ESCAPE	= 65307
}	t_keycode;

typedef struct t_window
{
	void		*mlx;
	void		*win;
	t_game_data	*data;
}	t_window;

typedef struct t_meta_data
{
	int	map_size_x;
	int	map_size_y;
	int	coll_num;
	int	total_moves;
}	t_meta_data;

typedef struct t_sprites
{
	void				*ptr;
	enum t_sprites_id	sprite_id;
}	t_sprites;

typedef struct t_map
{
	enum t_type	type;
	t_sprites	*sprites;
	int			version;
	int			is_exit_door;
}	t_map;

typedef struct t_player
{
	int	x;
	int	y;
}	t_player;

struct s_game_data
{
	t_sprites		sprites[SPRITES_NUM];
	t_window		win;
	t_meta_data		meta;
	t_map			**map;
	t_player		player;
};

int		check_map_is_valid(char *map_path);
int		init_data_structs(t_game_data **data, char *map_path);
void	free_data(t_game_data *data);
void	display_map(t_game_data *data);
int		key_hook(int keycode, t_window *win);
void	display_error(void);
int		handle_close_window(void *win);

#endif