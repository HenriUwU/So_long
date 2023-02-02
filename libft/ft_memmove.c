/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:22:08 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/10 16:21:27 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;

	if (dest == 0 && src == 0)
		return ((void *) 0);
	if (src >= dest)
	{
		ft_memcpy(dest, src, n);
	}
	mem1 = (unsigned char *)dest;
	mem2 = (unsigned char *)src;
	if (src < dest)
	{
		while (n > 0)
		{
			mem1[n - 1] = mem2[n - 1];
			n--;
		}
	}
	return (dest);
}
