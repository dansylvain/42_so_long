/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_structs_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:21:14 by dan               #+#    #+#             */
/*   Updated: 2024/01/15 09:50:07 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**========================================================================
 *                           get_sprite_path
 * path concatenation on the stack
 *! malloc from ft_itoa -freed immediately
 *========================================================================**/
char	*get_sprite_path(int i, char path_tmp[])
{
	char	*num;

	num = ft_itoa(i);
	ft_memset(path_tmp, '\0', 30);
	ft_strlcat(path_tmp, "assets/", 9);
	ft_strlcat(path_tmp, num, 11);
	ft_strlcat(path_tmp, ".xpm", 15);
	free(num);
	return (path_tmp);
}

/**========================================================================
 *                           display_map_tab
 *? dev tool
 *========================================================================**/
void	display_map_tab(t_game_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->meta.map_size_y)
	{
		j = 0;
		while (j < data->meta.map_size_x)
		{
			ft_printf("%i", data->map[i][j].type);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
