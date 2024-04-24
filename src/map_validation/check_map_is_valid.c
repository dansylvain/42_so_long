/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:43:02 by dan               #+#    #+#             */
/*   Updated: 2024/01/13 09:48:09 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_map_is_valid.h"
#include "../includes/so_long.h"

/**========================================================================
 *                           check_map_is_valid
 * This series of tests is independant from the rest of the program
 * ONLY CARRIED OUT TO CHECK MAP VALIDITY
 * All memory used is freed by the end of the process.
 *! ************* malloc's signaled in red ************
 *! memo allocation: map_char_tab 
 *========================================================================**/
int	check_map_is_valid(char *map_path)
{
	int		map_fd;
	char	**map_char_tab;
	int		map_size_y;
	int		map_size_x;

	if (is_ber_file(map_path) == 0)
		return (0);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (0);
	get_map_size(map_path, &map_size_x, &map_size_y);
	map_char_tab = (char **)ft_calloc(map_size_y + 1, sizeof(char *));
	if (map_char_tab == NULL)
		return (0);
	map_char_tab[map_size_y] = NULL;
	if (!turn_map_file_to_char_tab(map_fd, &map_char_tab))
		return (free (map_char_tab), 0);
	if (map_char_tab[0] == NULL)
		return (free (map_char_tab), 0);
	if (!call_check_functions(map_char_tab, map_path, map_size_x, map_size_y))
		return (free_map_char_tab(map_char_tab), 0);
	free_map_char_tab(map_char_tab);
	return (1);
}

/**========================================================================
 *                           call_check_functions
 *========================================================================**/
int	call_check_functions(char **map_char_tab,
	char *map_path, int map_size_x, int map_size_y)
{
	if (!check_chars_are_valid(map_char_tab))
		return (0);
	if (!check_line_length(map_char_tab, map_size_x))
		return (0);
	if (!check_walls(map_char_tab, map_size_x, map_size_y))
		return (0);
	if (!check_elements_are_reachable(map_char_tab, map_path))
		return (0);
	return (1);
}

/**========================================================================
 *                           is_ber_file
 *========================================================================**/
int	is_ber_file(char *map_path)
{
	while (*map_path)
	{
		if (strncmp(map_path, ".ber", 4) == 0)
			return (1);
		map_path++;
	}
	return (0);
}

/**========================================================================
 *                           get_map_size
 *========================================================================**/
void	get_map_size(char *map_path, int *map_size_x, int *map_size_y)
{
	int		map_fd;
	char	*str;

	*map_size_y = 0;
	*map_size_x = 0;
	map_fd = open(map_path, O_RDONLY);
	while (1)
	{
		str = get_next_line(map_fd);
		if (str == NULL)
			break ;
		(*map_size_y)++;
		*map_size_x = ft_strlen(str);
		free (str);
	}
	close (map_fd);
}

/**========================================================================
 *                           turn_map_file_to_char_tab
 *========================================================================**/
int	turn_map_file_to_char_tab(int map_fd, char ***map_char_tab)
{
	int		i;
	bool	map_char_tab_is_complete;
	char	*line;

	map_char_tab_is_complete = 0;
	i = 0;
	while (map_char_tab_is_complete == 0)
	{
		line = get_next_line(map_fd);
		if (line)
			(*map_char_tab)[i++] = clean_line(line);
		if (line == NULL)
			map_char_tab_is_complete = 1;
	}
	close (map_fd);
	return (1);
}
