/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_map_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:47:50 by dsylvain          #+#    #+#             */
/*   Updated: 2024/01/12 15:36:04 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/check_map_is_valid.h"

/**========================================================================
 *                           dfs_map_element
 * "depth first search" to check all reachable cells, a bit like floodfill
 * each time a non-wall or non-empty element is found, the struct is updated
 *========================================================================**/
void	dfs_map_element(char **map_char_table,
		int map_exploration[][MAP_SIZE_MAX], t_Mapdata *mapdata)
{
	int	x;
	int	y;

	x = mapdata->x;
	y = mapdata->y;
	if (x < 0 || y < 0 || map_exploration[y][x] || map_char_table[y][x] == '1')
		return ;
	map_exploration[y][x] = 1;
	if (map_char_table[y][x] == 'C')
		mapdata->collectible++;
	if (map_char_table[y][x] == 'P')
		mapdata->position++;
	if (map_char_table[y][x] == 'E')
		mapdata->exit++;
	mapdata->x = x + 1;
	dfs_map_element(map_char_table, map_exploration, mapdata);
	mapdata->x = x - 1;
	dfs_map_element(map_char_table, map_exploration, mapdata);
	mapdata->x = x;
	mapdata->y = y + 1;
	dfs_map_element(map_char_table, map_exploration, mapdata);
	mapdata->y = y - 1;
	dfs_map_element(map_char_table, map_exploration, mapdata);
	mapdata->x = x;
	mapdata->y = y;
}
