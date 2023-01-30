/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:00:57 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/30 19:48:07 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_map_logic(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.mapping[j])
	{
		i = 0;
		while (data.mapping[j][i])
		{
			if (data.mapping[j][i] != '1' && data.mapping[j][i] != 'E'
				&& data.mapping[j][i] != '0' && data.mapping[j][i] != 'P'
				&& data.mapping[j][i] != 'C')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

static int	is_duplicate(t_data data)
{
	int	i;
	int	j;
	int	checker1;
	int	checker2;

	i = 0;
	j = 0;
	checker1 = 0;
	checker2 = 0;
	while (data.mapping[j])
	{
		i = 0;
		while (data.mapping[j][i])
		{
			if (data.mapping[j][i] == 'P')
				checker1++;
			if (data.mapping[j][i] == 'E')
				checker2++;
			i++;
		}
		j++;
	}
	if (checker1 > 1 || checker2 > 1)
		return (0);
	return (1);
}

static int	is_rectangle(t_data data)
{
	int		i;
	size_t	reference;

	i = 1;
	reference = ft_strlen(data.mapping[0]);
	while (data.mapping[i])
	{
		if (ft_strlen(data.mapping[i]) != reference)
			return (0);
		i++;
	}
	return (1);
}

int	read_map(char **argv, t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-2);
	line = get_next_line(fd);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	data->mapping = ft_split(line, '\n');
	free(line);
	if (is_rectangle(*data) == 0)
		return (-1);
	if (is_duplicate(*data) == 0)
		return (-1);
	if (is_map_logic(*data) == 0)
		return (-1);
	return (0);
}
