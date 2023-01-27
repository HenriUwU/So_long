/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:50:48 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/27 21:11:38 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	got_all_collectible(t_data data)
{
	int	i;
	int	j;

	j = 0;
	while (data.mapping[j])
	{
		i = 0;
		while (data.mapping[j][i])
		{
			if (data.mapping[j][i] == 'C')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	portal_ready(t_data *data)
{
	int	i;
	int	j;

	if (data->mapping[data->py / 64][data->px / 64] == 'C')
		data->mapping[data->py / 64][data->px / 64] = '0';
	if (got_all_collectible(*data))
		return (1);
	else
		return (0);
}
