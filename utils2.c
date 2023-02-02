/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:11 by hsebille          #+#    #+#             */
/*   Updated: 2023/02/02 17:13:27 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_surrounded(t_data data)
{
	int	j;
	int	k;
	int	check;

	j = 0;
	k = 0;
	check = ft_strlen(data.mapping[0]) - 1;
	while (data.mapping[k])
		k++;
	while (data.mapping[0][j++])
		if (data.mapping[0][j - 1] != '1')
			return (0);
	j = 0;
	k--;
	while (data.mapping[k][j++])
		if (data.mapping[k][j - 1] != '1')
			return (0);
	while (k-- > 0)
		if (data.mapping[k][0] != '1' || data.mapping[k][check] != '1')
			return (0);
	return (1);
}
