/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:55:11 by dan               #+#    #+#             */
/*   Updated: 2024/01/15 09:49:05 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/move_funcs.h"

/**========================================================================
 *                             HOOKS.C
 *  Only one hook in base version, more to be added...
 *========================================================================**/
/**========================================================================
 *                           key_hook
 *========================================================================**/
int	key_hook(int keycode, t_window *win)
{
	if (keycode == KEY_ESCAPE)
		mlx_loop_end(win->mlx);
	else if (keycode == KEY_LEFT)
		move_left(win);
	else if (keycode == KEY_RIGHT)
		move_right(win);
	else if (keycode == KEY_DOWN)
		move_down(win);
	else if (keycode == KEY_UP)
		move_up(win);
	return (keycode);
}
