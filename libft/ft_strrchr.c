/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:04:08 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/01 15:27:50 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			size;
	unsigned char	a;

	size = 0;
	a = (unsigned char)c;
	while (s[size])
		size++;
	if (s[size] == a)
		return ((char *)s + size);
	while (size > 0)
	{
		if (s[size - 1] == a)
			return ((char *)s + size - 1);
		size--;
	}
	return ((void *) 0);
}
