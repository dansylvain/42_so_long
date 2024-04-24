/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_valid.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:45:42 by dan               #+#    #+#             */
/*   Updated: 2024/01/12 15:42:36 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_IS_VALID_H
# define CHECK_MAP_IS_VALID_H

# define MAP_SIZE_MAX 100

typedef struct s_Map_data
{
	int	x;
	int	y;
	int	collectible;
	int	position;
	int	exit;
}	t_Mapdata;

/*   check_map_is_valid.c                               :+:      :+:    :+:   */
int		check_map_is_valid(char *map_path);
int		call_check_functions(char **map_char_tab, char *map_path, int x, int y);
int		is_ber_file(char *map_path);
void	get_map_size(char *map_path, int *map_size_x, int *map_size_y);
int		turn_map_file_to_char_tab(int map_fd, char ***map_char_tab);

/*   check_map_is_valid_2.c                             :+:      :+:    :+:   */
int		check_chars_are_valid(char **map_char_tab);
int		check_line_length(char **map_char_tab, int map_size_x);
int		check_only_ones_in_line(char *line);
int		check_walls(char **map_char_tab, int map_size_x, int map_size_y);

/*   check_map_is_valid_utils.c                         :+:      :+:    :+:   */
char	*clean_line(char *line);
void	display_map_char_tab(char **map_char_tab);
void	free_map_char_tab(char **map_char_tab);

/*   check_elements_are_reachable.c                     :+:      :+:    :+:   */
int		check_elements_are_reachable(char **map_char_table, char *map_path);
void	initialize_tab_and_mapdata(int map_exploration[][MAP_SIZE_MAX],
			t_Mapdata *mapdata);
int		find_starting_position(char **map_char_table, t_Mapdata **mapdata);
void	create_exploration_table(char **map_char_table,
			int map_exploration[][MAP_SIZE_MAX]);

/*   check_elements_are_reachable_2.c                   :+:      :+:    :+:   */
int		check_elements_accessibility_through_quantity(t_Mapdata *mapdata,
			char **map_char_table, char *map_path);
int		get_collectible_quantity(char **map_char_table, char *map_path);
void	display_map_exploration(int map_exploration[][MAP_SIZE_MAX]);

/*   dfs_map_element.c                                  :+:      :+:    :+:   */
void	dfs_map_element(char **map_char_table,
			int map_exploration[][MAP_SIZE_MAX], t_Mapdata *mapdata);

#endif