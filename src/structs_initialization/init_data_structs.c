/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:12:02 by dan               #+#    #+#             */
/*   Updated: 2025/02/15 20:03:09 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/init_data_structs.h"
#include "../includes/init_data_structs_utils.h"

/**========================================================================
 *                             init_data_structs.c 
 *  all game data are initialized here.
 *  data structures are declared in so_long.h 
 *  sprite assets are refered to in paths.h
 *  
 *========================================================================**/
int	init_data_structs(t_game_data **data, char *map_path)
{
	*data = (t_game_data *)malloc(sizeof(t_game_data));
	if (*data == NULL)
		return (0);
	(*data)->meta.coll_num = 0;
	get_map_size(map_path, &(*data)->meta.map_size_x,
		&(*data)->meta.map_size_y);
	(*data)->meta.total_moves = 0;
	if (!init_struct_map_and_player(data, map_path))
		return (0);
	if (!init_struct_win_data(data))
		return (0);
	if (!init_struct_sprites(data))
	{
		ft_printf("init_struct_sprites returns 0\n");
		return (0);
	}
	return (1);
}

/**========================================================================
 *                           init_struct_map_and_player
 *! memo allocated for map
 *! freed by func "free_map" (file "free_data.c") 
 *========================================================================**/
int	init_struct_map_and_player(t_game_data **data, char *map_path)
{
	int	y;
	int	map_fd;
	int	x;

	(*data)->map = (t_map **)ft_calloc((*data)->meta.map_size_y + 1,
			sizeof(t_map *));
	if ((*data)->map == NULL)
		return (0);
	map_fd = open(map_path, O_RDONLY);
	y = 0;
	while (y < (*data)->meta.map_size_y + 1)
	{
		(*data)->map[y] = (t_map *)ft_calloc((*data)->meta.map_size_x + 1,
				sizeof(t_map));
		if ((*data)->map[y] == NULL)
			free_map(data);
		x = 0;
		if (!fill_map_tab(data, map_fd, y, x))
			break ;
		y++;
	}
	close (map_fd);
	return (1);
}

/**========================================================================
 *                           fill_map_tab
 * map struct filled according to map file content
 * other elements can be added in loop (see function below)
 *? => enum declaration should be modified too (file so_long.h)  
 *========================================================================**/
int	fill_map_tab(t_game_data **data, int map_fd, int y, int x)
{
	char	*line;

	line = get_next_line(map_fd);
	if (line == NULL)
		return (0);
	while (line[x] != '\n' && line[x] != '\0')
	{
		set_map_data(data, line, x, y);
		x++;
	}
	free (line);
	return (1);
}

/**========================================================================
 *                           set_map_data
 * map struct filled according to map file content
 *========================================================================**/
void	set_map_data(t_game_data **data, char*line, int x, int y)
{
	(*data)->map[y][x].is_exit_door = 0;
	if (line[x] == '0')
		(*data)->map[y][x].type = empty;
	if (line[x] == '1')
		(*data)->map[y][x].type = wall;
	if (line[x] == 'C')
	{
		(*data)->map[y][x].type = collectible;
		(*data)->meta.coll_num++;
	}
    if (line[x] == 'D')
        (*data)->map[y][x].type = dark_kristal;
	if (line[x] == 'P')
	{
		(*data)->map[y][x].type = position;
		(*data)->player.x = x;
		(*data)->player.y = y;
	}
	if (line[x] == 'E')
	{
		(*data)->map[y][x].is_exit_door = 1;
		(*data)->map[y][x].type = empty;
	}
}
