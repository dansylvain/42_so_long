/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_valid_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:54:45 by dan               #+#    #+#             */
/*   Updated: 2024/01/12 15:54:22 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_map_is_valid.h"
#include "../includes/so_long.h"

/**========================================================================
 *                           clean_line
 *========================================================================**/
char	*clean_line(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	if (line[len] == '\n')
		line[len] = '\0';
	return (line);
}

/**========================================================================
 *                           free_map_char_tab
 *========================================================================**/
void	free_map_char_tab(char **map_char_tab)
{
	int	y;

	y = 0;
	while (map_char_tab[y] != NULL)
		free(map_char_tab[y++]);
	free (map_char_tab);
}

/**========================================================================
 *                           display_map_char_tab
 *? dev only 
 *========================================================================**/
void	display_map_char_tab(char **map_char_tab)
{
	int	x;
	int	y;

	y = 0;
	while (map_char_tab[y])
	{
		x = 0;
		while (map_char_tab[y][x])
		{
			ft_printf("%c", map_char_tab[y][x]);
			x++;
		}
		ft_printf(" len: %i\n", ft_strlen(map_char_tab[y]));
		y++;
	}
}
