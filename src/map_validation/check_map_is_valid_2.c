/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_valid_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:51:09 by dan               #+#    #+#             */
/*   Updated: 2024/01/16 04:29:30 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_map_is_valid.h"
#include "../includes/so_long.h"

/**========================================================================
 *                           check_chars_are_valid
 * other chars can be added here if needed
 *========================================================================**/
int	check_chars_are_valid(char **map_char_tab)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map_char_tab[i] != NULL)
	{
		j = 0;
		while (map_char_tab[i][j])
		{
			c = map_char_tab[i][j];
			if (c != 'C' && c != 'E' && c != 'P' && c != '1' && c != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**========================================================================
 *                           check_line_length
 *========================================================================**/
int	check_line_length(char **map_char_tab, int map_size_x)
{
	int	i;

	i = 0;
	while (map_char_tab[i])
		if (ft_strlen (map_char_tab[i++]) != (size_t)map_size_x)
			return (0);
	return (1);
}

/**========================================================================
 *                           check_only_ones_in_line
 *========================================================================**/
int	check_only_ones_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

/**========================================================================
 *                           check_walls
 *========================================================================**/
int	check_walls(char **map_char_tab, int map_size_x, int map_size_y)
{
	int	i;

	if (check_only_ones_in_line(map_char_tab[0]) == 0)
		return (0);
	if (check_only_ones_in_line(map_char_tab[map_size_y - 1]) == 0)
		return (0);
	i = 0;
	while (map_char_tab[i])
	{
		if (map_char_tab[i][0] != '1')
			return (0);
		if (map_char_tab[i][map_size_x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
