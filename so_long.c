/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:35:47 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/27 20:40:23 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player1);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	keybind(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	else if ((keycode == XK_w || keycode == XK_Up) && can_move(*data))
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		mlx_put_image_to_window(data->mlx,
			data->win, data->player4, data->px, data->py - 64);
		data->py -= 64;
	}
	else if ((keycode == XK_s || keycode == XK_Down) && can_move2(*data))
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		mlx_put_image_to_window(data->mlx,
			data->win, data->player1, data->px, data->py + 64);
		data->py += 64;
	}
	else if ((keycode == XK_d || keycode == XK_Right) && can_move3(*data))
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		mlx_put_image_to_window(data->mlx,
			data->win, data->player3, data->px + 64, data->py);
		data->px += 64;
	}
	else if ((keycode == XK_a || keycode == XK_Left) && can_move4(*data))
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		mlx_put_image_to_window(data->mlx,
			data->win, data->player2, data->px - 64, data->py);
		data->px -= 64;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	data;

	data.x = 0;
	data.y = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window (data.mlx, 960, 320, "so_long");
	map_parsing(argv, &data);
	mlx_hook(data.win, 2, (1L << 0), keybind, &data);
	mlx_loop(data.mlx);
}
