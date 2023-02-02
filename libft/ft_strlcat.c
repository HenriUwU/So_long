/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:39:13 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/03 13:37:51 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	max_size;
	size_t	return_value;

	i = 0;
	if (size == 0 && !dst)
		return (ft_strlen(src));
	return_value = ft_strlen(dst) + ft_strlen(src);
	max_size = ft_strlen(dst);
	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	while (size > max_size + 1 && src[i])
	{
		dst[max_size] = src[i];
		max_size++;
		i++;
	}
	dst[max_size] = '\0';
	return (return_value);
}
