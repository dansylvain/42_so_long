/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:50:48 by dan               #+#    #+#             */
/*   Updated: 2024/01/15 09:42:22 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void	display_changed_elements(t_game_data	*data, int origin[2], int destination[2]);

/**========================================================================
 *                             move_funcs.c
 *  For now, the same block of code is copied four times.
 *  I shall figure out how to encapsulate this logis so to avoid repetition
 *========================================================================**/
/**========================================================================
 *                           move_left
 *========================================================================**/
void	move_left(t_window *win)
{
	int		x;
	int		y;
	t_type	*t;

	x = win->data->player.x;
	y = win->data->player.y;
	t = &(win->data->map[y][x - 1].type);
	if (*t != wall)
	{
		if (*t == collectible)
			win->data->meta.coll_num--;
		if (win->data->map[y][x - 1].is_exit_door == 1
			&& win->data->meta.coll_num == 0)
			mlx_loop_end(win->mlx);
		*t = position;
		win->data->map[y][x].type = empty;
		win->data->player.x -= 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	int or[2] = {x, y};
	int dest[2] = {x - 1, y};
	display_changed_elements(win->data, or, dest);
}

/**========================================================================
 *                           move_right
 *========================================================================**/
void	move_right(t_window *win)
{
	int		x;
	int		y;
	t_type	*t;

	x = win->data->player.x;
	y = win->data->player.y;
	t = &(win->data->map[y][x + 1].type);
	if (*t != wall)
	{
		if (*t == collectible)
			win->data->meta.coll_num--;
		if (win->data->map[y][x + 1].is_exit_door == 1
			&& win->data->meta.coll_num == 0)
			mlx_loop_end(win->mlx);
		*t = position;
		win->data->map[y][x].type = empty;
		win->data->player.x += 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	int or[2] = {x, y};
	int dest[2] = {x + 1, y};
	display_changed_elements(win->data, or, dest);
}

/**========================================================================
 *                           move_down
 *========================================================================**/
void	move_down(t_window *win)
{
	int		x;
	int		y;
	t_type	*t;

	x = win->data->player.x;
	y = win->data->player.y;
	t = &(win->data->map[y + 1][x].type);
	if (*t != wall)
	{
		if (*t == collectible)
			win->data->meta.coll_num--;
		if (win->data->map[y + 1][x].is_exit_door == 1
			&& win->data->meta.coll_num == 0)
			mlx_loop_end(win->mlx);
		*t = position;
		win->data->map[y][x].type = empty;
		win->data->player.y += 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	int or[2] = {x, y};
	int dest[2] = {x, y + 1};
	display_changed_elements(win->data, or, dest);
}

/**========================================================================
 *                           move_up
 *========================================================================**/
void	move_up(t_window *win)
{
	int		x;
	int		y;
	t_type	*t;

	x = win->data->player.x;
	y = win->data->player.y;
	t = &(win->data->map[y - 1][x].type);
	if (*t != wall)
	{
		if (*t == collectible)
			win->data->meta.coll_num--;
		if (win->data->map[y - 1][x].is_exit_door == 1
			&& win->data->meta.coll_num == 0)
			mlx_loop_end(win->mlx);
		*t = position;
		win->data->map[y][x].type = empty;
		win->data->player.y -= 1;
		win->data->meta.total_moves++;
		ft_printf("%i\n", win->data->meta.total_moves);
	}
	int or[2] = {x, y};
	int dest[2] = {x, y - 1};
	display_changed_elements(win->data, or, dest);
}
