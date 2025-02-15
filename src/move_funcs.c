/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:50:48 by dan               #+#    #+#             */
/*   Updated: 2025/02/15 19:47:31 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**========================================================================
 *                             move_funcs.c
 *  For now, the same block of code is copied four times.
 *  I shall figure out how to encapsulate this logis so to avoid repetition
 *========================================================================**/
/**========================================================================
 *                           move_left
 *========================================================================**/

void	inner_func(t_window *win, int x, int y)
{
    
	if (win->data->map[y][x].type == collectible)
		win->data->meta.coll_num--;
	if (win->data->meta.coll_num == 0)
		display_map_elements(win->data);
	if (win->data->map[y][x].is_exit_door == 1
		&& win->data->meta.coll_num == 0)
		mlx_loop_end(win->mlx);
	win->data->map[y][x].type = position;
}

void	move_left(t_window *win)
{
	int		x;
	int		y;
	int		or[2];
	int		dest[2];

	x = win->data->player.x;
	y = win->data->player.y;
	if (win->data->map[y][x - 1].type != wall)
	{
		inner_func(win, x - 1, y);
		win->data->map[y][x].type = empty;
		win->data->player.x -= 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	or[0] = x;
	or[1] = y;
	dest[0] = x - 1;
	dest[1] = y;
	display_changed_elements(win->data, or, dest);
}

/**========================================================================
 *                           move_right
 *========================================================================**/
void	move_right(t_window *win)
{
	int		x;
	int		y;
	int		or[2];
	int		dest[2];

	x = win->data->player.x;
	y = win->data->player.y;
	if (win->data->map[y][x + 1].type != wall)
	{
		inner_func(win, x + 1, y);
		win->data->map[y][x].type = empty;
		win->data->player.x += 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	or[0] = x;
	or[1] = y;
	dest[0] = x + 1;
	dest[1] = y;
	display_changed_elements(win->data, or, dest);
}

/**========================================================================
 *                           move_down
 *========================================================================**/
void	move_down(t_window *win)
{
	int		x;
	int		y;
	int		or[2];
	int		dest[2];

	x = win->data->player.x;
	y = win->data->player.y;
	if (win->data->map[y + 1][x].type != wall)
	{
		inner_func(win, x, y + 1);
		win->data->map[y][x].type = empty;
		win->data->player.y += 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	or[0] = x;
	or[1] = y;
	dest[0] = x;
	dest[1] = y + 1;
	display_changed_elements(win->data, or, dest);
}

/**========================================================================
 *                           move_up
 *========================================================================**/
void	move_up(t_window *win)
{
	int		x;
	int		y;
	int		or[2];
	int		dest[2];

	x = win->data->player.x;
	y = win->data->player.y;
	if (win->data->map[y - 1][x].type != wall)
	{
		inner_func(win, x, y - 1);
		win->data->map[y][x].type = empty;
		win->data->player.y -= 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	or[0] = x;
	or[1] = y;
	dest[0] = x;
	dest[1] = y - 1;
	display_changed_elements(win->data, or, dest);
}
