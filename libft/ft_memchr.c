/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:55:48 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/01 18:25:19 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	size_t			i;
	unsigned char	*str;

	i = 0;
	a = (unsigned char)c;
	if (a == 0 && n == 0)
		return ((void *) 0);
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == a)
			return (str + i);
		i++;
	}
	return ((void *) 0);
}
