/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:04:04 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/04 12:44:21 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start >= (size_t)ft_strlen(s) || len == 0)
		return (NULL);
	if (ft_strlen(s) - start >= len)
		substr = malloc(sizeof(char) * len + 1);
	else
		substr = malloc(sizeof(char) * ft_strlen(s) - start + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
