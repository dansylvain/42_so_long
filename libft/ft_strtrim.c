/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:43:35 by dan               #+#    #+#             */
/*   Updated: 2023/10/16 09:40:41 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	get_strtrim_len(char const *s1, char const *set)
{
	char	*strtrim_start;
	char	*strtrim_end;
	int		strtrim_len;

	while (is_in_set(*s1, set))
		s1++;
	strtrim_start = (char *)s1;
	while (*s1 != '\0')
		s1++;
	while (is_in_set(*s1, set) || *s1 == '\0')
		s1--;
	strtrim_end = (char *)s1;
	strtrim_len = strtrim_end - strtrim_start + 1;
	if (strtrim_len < 0)
		strtrim_len = 0;
	return (strtrim_len);
}

static void	fill_strtrim(char const *s1, char const *set,
int strtrim_len, char	*strtrim)
{
	int	i;

	while (is_in_set(*s1, set))
		s1++;
	i = 0;
	while (i < strtrim_len)
	{
		strtrim[i] = s1[i];
		i++;
	}
	strtrim[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		strtrim_len;

	strtrim_len = get_strtrim_len(s1, set);
	strtrim = (char *)malloc(sizeof(char) * (strtrim_len + 1));
	if (strtrim == NULL)
		return (NULL);
	fill_strtrim(s1, set, strtrim_len, strtrim);
	return (strtrim);
}
