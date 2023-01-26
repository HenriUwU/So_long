/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:35:47 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/26 15:01:49 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->character);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	keybind(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	else if (keycode == XK_w || keycode == XK_Up)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->character, data->x, data->y - 32);
		data->y -= 32;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	data;
	char	*line = NULL;
	int		i;
	int		fd;
	int		width;
	int		height;

	data.x = 0;
	data.y = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window (data.mlx, 960, 320, "so_long");
	data.ground = mlx_xpm_file_to_image(data.mlx, "./sprites/ground.xpm", &width, &height);
	data.character = mlx_xpm_file_to_image(data.mlx, "./sprites/Pink Monster/Pink_Monster.xpm", &width, &height);
	data.wall = mlx_xpm_file_to_image(data.mlx, "./sprites/wall.xpm", &width, &height);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '0')
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.ground, data.x, data.y);
				data.x += 32;
			}
			else if (line[i] == '1')
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.wall, data.x, data.y);
				data.x += 32;
			}
			else if (line[i] == 'P')
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.ground, data.x, data.y);
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.character, data.x, data.y);
				data.x += 32;
			}
			i++;
		}
		data.y += 32;
		data.x = 0;
		free(line);
		line = get_next_line(fd);
	}
	mlx_hook(data.mlx_win, 2, (1L << 0), keybind, &data);
	mlx_loop(data.mlx);
}
