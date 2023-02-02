/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:20:14 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/26 14:27:39 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	tracker;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	tracker = 0;
	while (src[i] != '\0')
	{
		tracker++;
		i++;
	}
	i = 0;
	if (size == 0)
		return (tracker);
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (tracker);
}
