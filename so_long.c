/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:35:47 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/25 22:21:40 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keybind

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	data;
	int		width;
	int		height;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window (data.mlx, 1920, 1080, "so_long");
	data.img = mlx_xpm_file_to_image(data.mlx, "./sprites/Pink Monster/Pink_Monster.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 50, 50);
	mlx_loop(data.mlx);
	mlx_key_hook(data.mlx_win, (*f)()
}
