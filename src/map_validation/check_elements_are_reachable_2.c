/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_are_reachable_2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:29:36 by dan               #+#    #+#             */
/*   Updated: 2024/01/16 04:30:27 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/check_map_is_valid.h"

/**========================================================================
 *                check_elements_accessibility_through_quantity
 *========================================================================**/
int	check_elements_accessibility_through_quantity(t_Mapdata *mapdata,
		char **map_char_table, char *map_path)
{
	int	collectible_quantity;

	collectible_quantity = get_collectible_quantity(map_char_table, map_path);
	if (mapdata->collectible != collectible_quantity)
		return (0);
	if (mapdata->exit != 1)
		return (0);
	if (mapdata->position != 1)
		return (0);
	return (1);
}

/**========================================================================
 *                       get_collectible_quantity
 *? since get_next_line returns NULL, it closes in a clean way
 *========================================================================**/
int	get_collectible_quantity(char **map_char_table, char *map_path)
{
	int		collectible_quantity;
	int		map_fd;
	char	*str;
	int		i;

	collectible_quantity = 0;
	map_fd = open(map_path, O_RDONLY);
	while (1)
	{
		str = get_next_line(map_fd);
		if (str == NULL)
			break ;
		i = 0;
		while (str[i])
		{
			if (str[i] == 'C')
				collectible_quantity++;
			i++;
		}
		free (str);
	}
	close (map_fd);
	return (collectible_quantity);
	(void)map_char_table;
}

/**========================================================================
 *                       display_map_exploration
 *? useful for developement
 *========================================================================**/
void	display_map_exploration(int map_exploration[][MAP_SIZE_MAX])
{
	int	y;
	int	x;

	y = 0;
	ft_printf("map_exploration: \n");
	while (y < 10)
	{
		x = 0;
		while (x < 50)
		{
			ft_printf("%i", map_exploration[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
