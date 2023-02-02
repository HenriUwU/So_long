/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:30:50 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/10 16:11:53 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	i = 0;
	if (dest == 0 && src == 0)
		return ((void *) 0);
	mem1 = (unsigned char *)dest;
	mem2 = (unsigned char *)src;
	while (n > 0)
	{
		mem1[i] = mem2[i];
		n--;
		i++;
	}
	return (dest);
}
