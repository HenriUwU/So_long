/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:03:23 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/27 20:45:29 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./libft/libft.h"
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
	void	*portal1;
	void	*portal2;
	void	*portal3;
	void	*portal4;
	void	*portal5;
	void	*portal6;
	void	*portal7;
	void	*portal8;
	char	**mapping;
	int		x;
	int		y;
	int		px;
	int		py;
	int		ex;
	int		ey;
}			t_data;

char	*get_next_line(int fd);
void	map_parsing(char **argv, t_data *data);
int		can_move(t_data data);
int		can_move2(t_data data);
int		can_move3(t_data data);
int		can_move4(t_data data);

#endif
