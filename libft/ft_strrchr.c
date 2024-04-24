/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:41:37 by dan               #+#    #+#             */
/*   Updated: 2023/10/16 08:17:07 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence;

	last_occurence = NULL;
	while (42)
	{
		if (*s == (unsigned char)c)
			last_occurence = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (last_occurence);
}
