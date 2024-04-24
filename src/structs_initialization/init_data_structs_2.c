/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_structs_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:33:59 by dan               #+#    #+#             */
/*   Updated: 2024/01/16 04:30:59 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/init_data_structs_utils.h"

/**========================================================================
 *                           init_struct_sprites
 *! func mlx_xpm_file_to_image allocates memory!
 *! freed by func "free_sprites" (file "free_data.c")
 *========================================================================**/
int	init_struct_sprites(t_game_data **data)
{
	int		i;
	char	path_tmp[30];
	int		width;
	int		height;

	i = 0;
	while (i < SPRITES_NUM)
	{
		get_sprite_path(i, path_tmp);
		(*data)->sprites[i].ptr = mlx_xpm_file_to_image((*data)->win.mlx,
				path_tmp, &width, &height);
		if (!(*data)->sprites[i].ptr)
			return (0);
		(*data)->sprites[i].sprite_id = i;
		i++;
	}
	return (1);
}

/**========================================================================
 *                           init_struct_win_data
 *! func mlx_new_window and mlx_new_window both allocate memory!
 *! freed by func "free_window" (file "free_data.c")
 *========================================================================**/
int	init_struct_win_data(t_game_data **data)
{
	int			x;
	int			y;
	t_window	*win;

	x = (*data)->meta.map_size_x;
	y = (*data)->meta.map_size_y;
	win = &(*data)->win;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	win->win = mlx_new_window(win->mlx, x * 64, y * 64, "Hello world!");
	if (!win->win)
		return (mlx_destroy_display(win->mlx), 0);
	win->data = *data;
	return (1);
}
