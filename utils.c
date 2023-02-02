/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:50:48 by hsebille          #+#    #+#             */
/*   Updated: 2023/02/01 20:35:21 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_mapping(char **mapping_copy, t_data *data)
{
	int	i;

	i = 0;
	while (data->mapping[i])
		i++;
	mapping_copy = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (data->mapping[i])
	{
		mapping_copy[i] = ft_strdup(data->mapping[i]);
		i++;
	}
	return (mapping_copy);
}

static void	free_copy(char **copy)
{
	int	i;

	if (!copy)
		return ;
	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

static void	pathfinder(char **mapping_copy, int px, int py)
{
	if (mapping_copy[py - 1][px] != '1' && mapping_copy[py - 1][px] != 'H')
	{
		mapping_copy[py - 1][px] = 'H';
		pathfinder(mapping_copy, px, py - 1);
	}
	if (mapping_copy[py + 1][px] != '1' && mapping_copy[py + 1][px] != 'H')
	{
		mapping_copy[py + 1][px] = 'H';
		pathfinder(mapping_copy, px, py + 1);
	}
	if (mapping_copy[py][px - 1] != '1' && mapping_copy[py][px - 1] != 'H')
	{
		mapping_copy[py][px - 1] = 'H';
		pathfinder(mapping_copy, px - 1, py);
	}
	if (mapping_copy[py][px + 1] != '1' && mapping_copy[py][px + 1] != 'H')
	{
		mapping_copy[py][px + 1] = 'H';
		pathfinder(mapping_copy, px + 1, py);
	}
}

int	find_player(t_data *data)
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
				data->px2 = j;
				data->py2 = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_map_feasible(char **mapping_copy, t_data *data, int x, int y)
{
	int	i;
	int	j;

	find_player(data);
	j = 0;
	mapping_copy = copy_mapping(mapping_copy, data);
	pathfinder(mapping_copy, x, y);
	while (mapping_copy[j])
	{
		i = 0;
		while (mapping_copy[j][i])
		{
			if (mapping_copy[j][i] != 'H'
				&& mapping_copy[j][i] != '1'
				&& mapping_copy[j][i] != '0')
			{
				free_copy(mapping_copy);
				return (1);
			}
			i++;
		}
		j++;
	}
	free_copy(mapping_copy);
	return (0);
}
