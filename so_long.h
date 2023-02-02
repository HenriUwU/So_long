/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:03:23 by hsebille          #+#    #+#             */
/*   Updated: 2023/02/02 16:58:42 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# define BUFFER_SIZE 1

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*ground;
	void	*wall;
	void	*collectible;
	void	*portal;
	char	**mapping;
	char	**mapping_copy;
	int		checker_player;
	int		checker_exit;
	int		checker_collectible;
	int		mvmt_count;
	int		xmap;
	int		ymap;
	int		x;
	int		y;
	int		px;
	int		py;
	int		px2;
	int		py2;
	int		ex;
	int		ey;
}			t_data;

void	close_game(t_data *data);
void	close_window(t_data *data);
void	destroy_mapping(t_data *data, int booleen);
char	*get_next_line(int fd);
int		is_map_surrounded(t_data data);
int		is_player_collectible_exit(t_data *data);
int		find_player(t_data *data);
int		is_map_feasible(char **mapping_copy, t_data *data, int x, int y);
int		mouse_close(t_data *data);
int		gameplay(int keycode, t_data *data);
int		read_map(char **argv, t_data *data);
int		draw_map(t_data *data);
int		portal_ready(t_data *data);
int		can_move(t_data *data);
int		can_move2(t_data *data);
int		can_move3(t_data *data);
int		can_move4(t_data *data);

#endif
