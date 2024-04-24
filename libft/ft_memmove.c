/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:04:26 by dan               #+#    #+#             */
/*   Updated: 2023/10/23 09:53:57 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	memmove_backwards(void *dest, const void *src, size_t n)
{
	while (n > 0)
	{
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
}

static void	memmove_forward(void *dest, const void *src, size_t n)
{
	while (n > 0)
	{
		*(char *)dest++ = *(char *)src++;
		n--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (src < dest && dest < src + n)
		memmove_backwards(dest, src, n);
	else
		memmove_forward(dest, src, n);
	return (dest);
}
