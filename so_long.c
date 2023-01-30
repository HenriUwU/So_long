/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:35:47 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/30 21:25:23 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->mvmt_count = 0;
	data->xmap = ft_strlen(data->mapping[0]);
	data->ymap = 0;
	while (data->mapping[data->ymap])
		data->ymap++;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		checker;

	if (argc != 2)
	{
		write(2, "Error: invalid arguments.\n", 26);
		return (1);
	}
	checker = read_map(argv, &data);
	if (checker < 0)
	{
		if (checker == -1)
			close_window(&data);
		else
			write(2, "Error: bad inputs.\n", 19);
		return (1);
	}
	init_vars(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.xmap * 64,
			data.ymap * 64, argv[0]);
	checker = draw_map(&data);
	if (checker < 0)
	{
		write(2, "Error: No path found.\n", 22);
		close_game(&data);
	}
	mlx_hook(data.win, 2, (1L << 0), gameplay, &data);
	mlx_hook(data.win, 17, 4, mouse_close, &data);
	mlx_loop(data.mlx);
}
