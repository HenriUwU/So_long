/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:13 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/13 12:34:56 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;
	int				i;

	if (s == NULL)
		return (NULL);
	i = 0;
	a = (unsigned char)c;
	while (s[i] != a && s[i])
		i++;
	if (s[i] == a)
		return ((char *)s + i);
	return ((void *) 0);
}
