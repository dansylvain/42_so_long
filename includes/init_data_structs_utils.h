/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_structs_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:22:50 by dan               #+#    #+#             */
/*   Updated: 2024/01/14 16:22:37 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_DATA_STRUCTS_UTILS_H
# define INIT_DATA_STRUCTS_UTILS_H

void	free_map(t_game_data **data);
void	free_data(t_game_data *data);
int		fill_map_tab(t_game_data **data, int map_fd, int y, int x);
void	display_map_tab(t_game_data *data);
char	*get_sprite_path(int i, char path_tmp[]);
void	set_map_data(t_game_data **data, char*line, int x, int y);

#endif