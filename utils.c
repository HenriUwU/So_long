/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:50:48 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/30 22:09:57 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_mapping(char **mapping_copy, t_data *data)
{
	int	i;

	i = 0;
	while (data->mapping[i])
		i++;
	mapping_copy = malloc(sizeof(char *) * i);
	i = 0;
	while (data->mapping[i])
	{
		mapping_copy[i] = ft_strdup(data->mapping[i]);
		i++;
	}
	return (mapping_copy);
}

static void	pathfinder(char **mapping_copy, int px, int py)
{
	if (mapping_copy[(py / 64) - 1][px / 64] != '1')
	{
		mapping_copy[(py / 64) - 1][px / 64] = 'H';
		pathfinder(mapping_copy, px, (py - 64));
		return ;
	}
	if (mapping_copy[(py / 64) + 1][px / 64] != '1')
	{
		mapping_copy[(py / 64) + 1][px / 64] = 'H';
		pathfinder(mapping_copy, px, py + 64);
		return ;
	}
	if (mapping_copy[py / 64][(px / 64) - 1] != '1')
	{
		mapping_copy[py / 64][(px / 64) - 1] = 'H';
		pathfinder(mapping_copy, px - 64, py);
		return ;
	}
	if (mapping_copy[py / 64][(px / 64) + 1] != '1')
	{
		mapping_copy[py / 64][(px / 64) + 1] = 'H';
		pathfinder(mapping_copy, px + 64, py);
		return ;
	}
}

static int	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mapping[i])
	{
		j = 0;
		while (data->mapping[i][j])
		{
			if (data->mapping[i][j] == 'P')
			{
				data->px = j;
				data->py = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static char	**pathfinding(char **mapping_copy, t_data *data, int x, int y)
{
	int	i;
	int	j;

	find_player(data);
	j = data->py;
	i = data->py;
	mapping_copy = copy_mapping(mapping_copy, data);
	while (mapping_copy[i])
	{
		while (mapping_copy[i][j])
		{
			pathfinder(mapping_copy, x, y);
			j++;
		}
		i++;
	}
	return (data->mapping_copy);
}


int	is_map_feasible(char **mapping_copy, t_data *data, int x, int y)
{
	int	i;
	int	j;

	find_player(data);
	j = data->py;
	i = data->py;
	mapping_copy = pathfinding(mapping_copy, data, x, y);
	while (data->mapping_copy)
	{
		while (data->mapping_copy[j][i])
		{
			if (data->mapping_copy[j][i] != 'H'
				&& data->mapping_copy[j][i] != '1')
				return (0);
			i++;
		}
		j++;
	}
	return (0);
}

int	got_all_collectible(t_data data)
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
