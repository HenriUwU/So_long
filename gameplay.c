/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:56:11 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/30 19:05:44 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	keybind_actions1(t_data *data, void *player, char c)
{
	if (c == 'w')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		data->py -= 64;
		mlx_put_image_to_window(data->mlx,
			data->win, player, data->px, data->py);
		data->mvmt_count++;
	}
	else if (c == 'a')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		data->px -= 64;
		mlx_put_image_to_window(data->mlx,
			data->win, player, data->px, data->py);
		data->mvmt_count++;
	}
	if (data->mapping[data->py / 64][data->px / 64] == 'C')
		data->mapping[data->py / 64][data->px / 64] = '0';
}

static void	keybind_actions2(t_data *data, void *player, char c)
{
	if (c == 's')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		data->py += 64;
		mlx_put_image_to_window(data->mlx,
			data->win, player, data->px, data->py);
		data->mvmt_count++;
	}
	else if (c == 'd')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->ground, data->px, data->py);
		data->px += 64;
		mlx_put_image_to_window(data->mlx,
			data->win, player, data->px, data->py);
		data->mvmt_count++;
	}
	if (data->mapping[data->py / 64][data->px / 64] == 'C')
		data->mapping[data->py / 64][data->px / 64] = '0';
}

int	gameplay(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_game(data);
	else if ((keycode == XK_w || keycode == XK_Up) && can_move(data))
		keybind_actions1(data, data->player4, 'w');
	else if ((keycode == XK_s || keycode == XK_Down) && can_move2(data))
		keybind_actions2(data, data->player1, 's');
	else if ((keycode == XK_d || keycode == XK_Right) && can_move3(data))
		keybind_actions2(data, data->player3, 'd');
	else if ((keycode == XK_a || keycode == XK_Left) && can_move4(data))
		keybind_actions1(data, data->player2, 'a');
	if (got_all_collectible(*data))
		mlx_put_image_to_window(data->mlx,
			data->win, data->portal, data->ex, data->ey);
	if (got_all_collectible(*data)
		&& data->mapping[data->py / 64][data->px / 64] == 'E')
		close_game(data);
	ft_printf("Movement count : %d\n", data->mvmt_count);
	return (0);
}
