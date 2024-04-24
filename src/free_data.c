/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:44:28 by dsylvain          #+#    #+#             */
/*   Updated: 2024/01/16 05:05:38 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/free_data.h"

/**========================================================================
 *                           free_data
 *========================================================================**/
void	free_data(t_game_data *data)
{
	free_sprites(&data);
	free_window(data);
	free_map(&data);
	free(data);
}

/**========================================================================
 *                           free_sprites
 *========================================================================**/
void	free_sprites(t_game_data **data)
{
	int	i;

	i = 0;
	while (i < SPRITES_NUM)
	{
		mlx_destroy_image((*data)->win.mlx, (*data)->sprites[i].ptr);
		i++;
	}
}

/**========================================================================
 *                           free_window
 *========================================================================**/
void	free_window(t_game_data	*data)
{
	mlx_destroy_window(data->win.mlx, data->win.win);
	mlx_destroy_display(data->win.mlx);
	free(data->win.mlx);
}

/**========================================================================
 *                           free_map
 *========================================================================**/
void	free_map(t_game_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->meta.map_size_y + 1)
	{
		if ((*data)->map[i])
			free((*data)->map[i++]);
	}
	if ((*data)->map)
		free((*data)->map);
}
