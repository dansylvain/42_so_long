/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:00:32 by dan               #+#    #+#             */
/*   Updated: 2023/10/30 07:25:42 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*delete_data(t_Data **head, int fd)
{
	t_Data	*current;
	t_Data	*node_to_delete;

	node_to_delete = NULL;
	current = *head;
	if (current->fd == fd)
	{
		*head = current->next;
		node_to_delete = current;
	}
	else
	{
		while (current->next)
		{
			if (current->next->fd == fd)
			{
				node_to_delete = current->next;
				current->next = current->next->next;
				break ;
			}
			current = current->next;
		}
	}
	delete_node(node_to_delete);
	return (NULL);
}

void	*delete_node(t_Data *node_to_delete)
{
	if (node_to_delete)
	{
		free(node_to_delete->buff_nl);
		free(node_to_delete->buffer);
		node_to_delete->buff_nl = NULL;
		node_to_delete->buffer = NULL;
		free(node_to_delete);
		node_to_delete = NULL;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if ((start + len) > ft_strlen(s))
		substr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if ((char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
