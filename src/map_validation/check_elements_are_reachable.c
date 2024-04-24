/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_are_reachable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:41 by dan               #+#    #+#             */
/*   Updated: 2024/01/12 15:29:30 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/check_map_is_valid.h"

/**========================================================================
 *                      check_elements_are_reachable.c
 *  the heart of this part if the depth first search algorithm
 *! a struct is malloc'd for it and freed once the check was carried out 
 *! VERIF DONE ON THE STACK!!! LIMITS: map size MAP_SIZE_MAX (map_is_valid.h) 
 *========================================================================**/
int	check_elements_are_reachable(char **map_char_table, char *map_path)
{
	t_Mapdata	*mapdata;
	int			map_exploration[MAP_SIZE_MAX][MAP_SIZE_MAX];

	mapdata = (t_Mapdata *)malloc(sizeof(t_Mapdata));
	if (mapdata == NULL)
		return (0);
	initialize_tab_and_mapdata(map_exploration, mapdata);
	create_exploration_table(map_char_table, map_exploration);
	if (!find_starting_position(map_char_table, &mapdata))
		return (free(mapdata), 0);
	dfs_map_element(map_char_table, map_exploration, mapdata);
	if (!check_elements_accessibility_through_quantity(mapdata,
			map_char_table, map_path))
		return (free(mapdata), 0);
	free(mapdata);
	return (1);
}

/**========================================================================
 *                           initialize_tab_and_mapdata
 *? important to avoid valgrind errors :)
 *========================================================================**/
void	initialize_tab_and_mapdata(int map_exploration[][MAP_SIZE_MAX],
		t_Mapdata *mapdata)
{
	int	y;
	int	x;

	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			map_exploration[y][x] = 0;
			x++;
		}
		y++;
	}
	mapdata->collectible = 0;
	mapdata->exit = 0;
	mapdata->position = 0;
}

/**========================================================================
 *                           find_starting_position
 *? return as soon as one position is found... in case there ar more than one!
 *========================================================================**/
int	find_starting_position(char **map_char_table, t_Mapdata **mapdata)
{
	(*mapdata)->y = 0;
	while (map_char_table[(*mapdata)->y] != NULL)
	{
		(*mapdata)->x = 0;
		while (map_char_table[(*mapdata)->y][(*mapdata)->x] != '\0')
		{
			if (map_char_table[(*mapdata)->y][(*mapdata)->x] == 'P')
				return (1);
			((*mapdata)->x)++;
		}
		((*mapdata)->y)++;
	}
	return (0);
}

/**========================================================================
 *                           create_exploration_table
 *? useful to mark already explored fields durinf depth first search
 *========================================================================**/
void	create_exploration_table(char **map_char_table,
	int map_exploration[][MAP_SIZE_MAX])
{
	int	x;
	int	y;

	y = 0;
	while (map_char_table[y])
	{
		x = 0;
		while (map_char_table[y][x])
		{
			if (map_char_table[y][x] == '1')
				map_exploration[y][x] = 1;
			x++;
		}
		y++;
	}
}
