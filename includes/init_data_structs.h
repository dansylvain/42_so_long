/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:14:15 by dan               #+#    #+#             */
/*   Updated: 2024/01/16 04:23:54 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_DATA_STRUCTS_H
# define INIT_DATA_STRUCTS_H

/*   init_structs.c                                     :+:      :+:    :+:   */
int		init_struct_win_data(t_game_data **data);
int		init_struct_map_and_player(t_game_data **data, char *map_path);
int		init_struct_sprites(t_game_data **data);
int		init_data_structs(t_game_data **data, char *map_path);
void	get_map_size(char *map_path, int *map_size_x, int *map_size_y);

#endif