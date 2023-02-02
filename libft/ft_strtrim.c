/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:24:39 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/06 16:36:30 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*output;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (ft_is_in(s1[i], set) == 1)
		i++;
	while (ft_is_in(s1[j - 1], set) == 1)
		j--;
	output = ft_substr(s1, i, (j - i));
	if (output == NULL)
		return (NULL);
	return (output);
}
