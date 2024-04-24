/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:15:24 by dan               #+#    #+#             */
/*   Updated: 2024/01/14 16:22:37 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_DATA_H
# define FREE_DATA_H

void	free_data(t_game_data *data);
void	free_sprites(t_game_data **data);
void	free_window(t_game_data	*data);
void	free_map(t_game_data **data);

#endif
