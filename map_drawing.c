/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:05:26 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/30 21:53:42 by hsebille         ###   ########.fr       */
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
	data->portal = mlx_xpm_file_to_image(data->mlx,
			"sprites/portal.xpm", &width, &height);
}

static void	draw_ground_wall_collectible(t_data *data, char c)
{
	if (c == '0')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->x, data->y);
	}
	if (c == '1')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->wall, data->x, data->y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->collectible, data->x, data->y);
	}
}

static void	draw_player_exit(t_data *data, char c)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->player1, data->x, data->y);
		data->px = data->x;
		data->py = data->y;
	}
	if (c == 'E')
	{
		data->ex = data->x;
		data->ey = data->y;
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->x, data->y);
	}
}

static void	draw_img(int i, int j, t_data *data)
{
	if (data->mapping[j][i] == '0')
		draw_ground_wall_collectible(data, '0');
	else if (data->mapping[j][i] == '1')
		draw_ground_wall_collectible(data, '1');
	else if (data->mapping[j][i] == 'C')
		draw_ground_wall_collectible(data, 'C');
	else if (data->mapping[j][i] == 'P')
		draw_player_exit(data, 'P');
	else if (data->mapping[j][i] == 'E')
		draw_player_exit(data, 'E');
	i++;
}

int	draw_map(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	files_to_image(data);
	while (data->mapping[j] != NULL)
	{
		i = 0;
		while (data->mapping[j][i])
		{
			draw_img(i, j, data);
			data->x += 64;
			i++;
		}
		data->y += 64;
		data->x = 0;
		j++;
	}
	data->py2 = data->py;
	data->px2 = data->px;
	if (is_map_feasible(data->mapping_copy, data, data->px2, data->py2) == 0)
		return (-1);
	return (0);
}
