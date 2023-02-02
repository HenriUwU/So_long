/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:12:49 by hsebille          #+#    #+#             */
/*   Updated: 2023/02/02 16:58:03 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player1);
	mlx_destroy_image(data->mlx, data->player2);
	mlx_destroy_image(data->mlx, data->player3);
	mlx_destroy_image(data->mlx, data->player4);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->portal);
}

void	destroy_mapping(t_data *data, int booleen)
{
	int	i;

	i = 0;
	while (data->mapping[i])
	{
		free(data->mapping[i]);
		i++;
	}
	free(data->mapping);
	if (booleen == 1)
		write (2, "Error: Map is not valid.\n", 25);
}

void	close_game(t_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	destroy_mapping(data, 0);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	close_window(t_data *data)
{
	destroy_mapping(data, 1);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	mouse_close(t_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	destroy_mapping(data, 0);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
