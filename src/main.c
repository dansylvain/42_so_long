/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:57:35 by dan               #+#    #+#             */
/*   Updated: 2025/02/15 19:53:13 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int loop_hook(t_game_data	*data)
{
    data->frame_count++;

    if (data->frame_count % 30000 == 0)
        printf("1 seconde écoulée !\n");

    return (0);
}


/**========================================================================
 *                             SO_LONG
 *  function check_map_is_valid carries out multiple checks of validity
 *  init_data_structs initializes all game data structs
 *  
 *  
 *========================================================================**/
int	main(int argc, char **argv)
{
	t_game_data	*data;
	if (argc != 2)
        return (display_error(), 255);
    if (!check_map_is_valid(argv[1]))
        return (display_error(), 255);
    if (!init_data_structs(&data, argv[1]))
        return (free_data(data), display_error(), 255);
    display_map(data);
    mlx_hook(data->win.win, 17, 0L, handle_close_window, &data->win);
    mlx_hook(data->win.win, 3, (1L << 0) + (1L << 1), key_hook, &data->win);

    data->frame_count = 0;
    mlx_loop_hook(data->win.mlx, (void *)loop_hook, &data);
    
	mlx_loop(data->win.mlx);
	free_data(data);
	return (0);
}
