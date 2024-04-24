/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:57:06 by dan               #+#    #+#             */
/*   Updated: 2024/01/13 16:53:47 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbr_str_len(long int n)
{
	int	nbr_str_len;

	nbr_str_len = 0;
	if (n < 0)
	{
		nbr_str_len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		nbr_str_len++;
	}
	nbr_str_len++;
	return (nbr_str_len);
}

static void	fill_nbr_str(long int n, char *nbr_str, int nbr_str_len)
{
	nbr_str[nbr_str_len] = '\0';
	if (n == 0)
	{
		nbr_str[0] = '0';
		return ;
	}
	if (n < 0)
	{
		n = -n;
		nbr_str[0] = '-';
	}
	while (n > 0)
	{
		nbr_str[nbr_str_len -1] = (n % 10) + '0';
		n /= 10;
		nbr_str_len--;
	}
}

char	*ft_itoa(int n)
{
	char	*nbr_str;
	int		nbr_str_len;

	nbr_str_len = get_nbr_str_len((long int)n);
	nbr_str = (char *)ft_calloc((nbr_str_len + 1), sizeof(char));
	if (nbr_str == NULL)
		return (NULL);
	fill_nbr_str((long int) n, nbr_str, nbr_str_len);
	return (nbr_str);
}
