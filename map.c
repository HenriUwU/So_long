/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:05:26 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/27 21:11:43 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	files_to_image(t_data *data)
{
	int	width;
	int	height;

	data->ground = mlx_xpm_file_to_image(data->mlx,
			"sprites/ground.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"sprites/wall.xpm", &width, &height);
	data->player1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/player1.xpm", &width, &height);
	data->player2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/player2.xpm", &width, &height);
	data->player3 = mlx_xpm_file_to_image(data->mlx,
			"sprites/player3.xpm", &width, &height);
	data->player4 = mlx_xpm_file_to_image(data->mlx,
			"sprites/player4.xpm", &width, &height);
	data->collectible = mlx_xpm_file_to_image(data->mlx,
			"sprites/collectible.xpm", &width, &height);
}

static void	portal_files_to_image(t_data *data)
{
	int	width;
	int	height;

	data->portal = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame0.xpm", &width, &height);
	data->portal1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame1.xpm", &width, &height);
	data->portal2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame2.xpm", &width, &height);
	data->portal3 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame3.xpm", &width, &height);
	data->portal4 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame4.xpm", &width, &height);
	data->portal5 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame5.xpm", &width, &height);
	data->portal6 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame6.xpm", &width, &height);
	data->portal7 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame7.xpm", &width, &height);
	data->portal8 = mlx_xpm_file_to_image(data->mlx,
			"sprites/Portal/frame8.xpm", &width, &height);
}

static void	image_to_window(t_data *data, void *image)
{
	mlx_put_image_to_window(data->mlx,
		data->win, image, data->x, data->y);
	data->x += 64;
}

static void	parsing_conditions(int i, int j, t_data *data)
{
	files_to_image(data);
	if (data->mapping[j][i] == '0')
		image_to_window(data, data->ground);
	else if (data->mapping[j][i] == '1')
		image_to_window(data, data->wall);
	else if (data->mapping[j][i] == 'C')
		image_to_window(data, data->collectible);
	else if (data->mapping[j][i] == 'P')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->player1, data->x, data->y);
		data->px = data->x;
		data->py = data->y;
		data->x += 64;
	}
	else if (data->mapping[j][i] == 'E')
	{
		data->ex = data->x;
		data->ey = data->y;
	}
	i++;
}

void	map_parsing(char **argv, t_data *data)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(line);
	data->mapping = ft_split(line, '\n');
	j = 0;
	while (data->mapping[j] != NULL)
	{
		i = 0;
		while (data->mapping[j][i])
		{
			parsing_conditions(i, j, data);
			i++;
		}
		data->y += 64;
		data->x = 0;
		j++;
	}
}

void	portal_spawning(t_data *data)
{
	if (portal_ready(data))
		mlx_put_image_to_window ()
}
