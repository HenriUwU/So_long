/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:35:47 by hsebille          #+#    #+#             */
/*   Updated: 2023/02/02 19:19:11 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_vars(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->checker_player = 0;
	data->checker_exit = 0;
	data->checker_collectible = 0;
	data->mvmt_count = 0;
	data->xmap = ft_strlen(data->mapping[0]);
	data->ymap = 0;
	while (data->mapping[data->ymap])
		data->ymap++;
}

static int	is_not_ber(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1], ".ber", 4) == 0)
		return (1);
	if (argv[1][i - 1] != 'r')
		return (1);
	if (argv[1][i - 2] != 'e')
		return (1);
	if (argv[1][i - 3] != 'b')
		return (1);
	if (argv[1][i - 4] != '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		checker;

	if (argc != 2)
		return (write(2, "Error: invalid number of arguments.\n", 36));
	if (is_not_ber(argv))
		return (write(2, "Error: file is not a .ber\n", 26));
	checker = read_map(argv, &data);
	if (checker < 0)
	{
		if (checker == -1)
			destroy_mapping(&data, 1);
		else
			return (write(2, "Error: bad inputs.\n", 19));
		return (0);
	}
	init_vars(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.xmap * 64,
			data.ymap * 64, argv[0]);
	if (draw_map(&data) < 0)
		close_window(&data);
	mlx_hook(data.win, 2, (1L << 0), gameplay, &data);
	mlx_hook(data.win, 17, 4, mouse_close, &data);
	mlx_loop(data.mlx);
}
