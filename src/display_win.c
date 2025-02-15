/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:44:59 by dan               #+#    #+#             */
/*   Updated: 2025/02/15 20:01:17 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/display_win.h"

/**========================================================================
 *                           display_map
 *? for now, these functions simply display the sprites as they are
 *! transparency to be implemented!!! 
 *? add this code for move_num display on window
 	num_str = ft_itoa(data->meta.total_moves);
	mlx_string_put(data->win.mlx, data->win.win,
		5, 15, 0xFFFFFF, num_str);
	free(num_str);
 *========================================================================**/
void	display_map(t_game_data *data)
{
	display_map_background(data);
	display_map_elements(data);
}

/**========================================================================
 *                           display_map_background
 *? to display first. Border could be added once transparency is implemented 
 *========================================================================**/
void	display_map_background(t_game_data	*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->meta.map_size_y)
	{
		x = 0;
		while (x < data->meta.map_size_x)
		{
			mlx_put_image_to_window(data->win.mlx, data->win.win,
				data->sprites[S_GROUND_00].ptr, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

/**========================================================================
 *                           display_map_elements
 *========================================================================**/
void	display_map_elements(t_game_data	*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->meta.map_size_y)
	{
		x = 0;
		while (x < data->meta.map_size_x)
		{
			if (data->map[y][x].type == wall)
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->sprites[S_ROCK_00].ptr, x * 64, y * 64);
			if (data->map[y][x].type == collectible)
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->sprites[S_CRYSTAL_20].ptr, x * 64, y * 64);
            if (data->map[y][x].type == dark_kristal)
                mlx_put_image_to_window(data->win.mlx, data->win.win,
                    data->sprites[S_CRYSTAL_00].ptr, x * 64, y * 64);    
            if (data->map[y][x].is_exit_door == 1 && data->meta.coll_num == 0)
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->sprites[S_CRYSTAL_41].ptr, x * 64, y * 64);
			if (data->map[y][x].type == position)
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->sprites[S_CHAR_SPRITE].ptr, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	display_elements(t_game_data *data, int origin[2],
		int destination[2], int xy[2])
{
	int	is_changed;

	is_changed = ((xy[0] == destination[0] && xy[1] == destination[1])
			|| (xy[0] == origin[0] && xy[1] == origin[1]));
	if (data->map[xy[1]][xy[0]].type == wall && is_changed)
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->sprites[S_ROCK_00].ptr, xy[0] * 64, xy[1] * 64);
	else if (data->map[xy[1]][xy[0]].type == collectible && is_changed)
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->sprites[S_CRYSTAL_20].ptr, xy[0] * 64, xy[1] * 64);
	else if (data->map[xy[1]][xy[0]].is_exit_door == 1
		&& data->meta.coll_num == 0 && is_changed)
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->sprites[S_CRYSTAL_41].ptr, xy[0] * 64, xy[1] * 64);
	else if (data->map[xy[1]][xy[0]].type == position && is_changed)
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->sprites[S_CHAR_SPRITE].ptr, xy[0] * 64, xy[1] * 64);
	else if (is_changed)
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->sprites[S_GROUND_00].ptr, xy[0] * 64, xy[1] * 64);
	xy[0]++;
}

void	display_changed_elements(t_game_data *data, int origin[2],
		int destination[2])
{
	int	xy[2];

	xy[1] = 0;
	while (xy[1] < data->meta.map_size_y)
	{
		xy[0] = 0;
		while (xy[0] < data->meta.map_size_x)
			display_elements(data, origin, destination, xy);
		xy[1]++;
	}
}
