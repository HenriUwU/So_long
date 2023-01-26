/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:03:23 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/26 14:03:49 by hsebille         ###   ########.fr       */
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
	void	*mlx_win;
	void	*character;
	void	*ground;
	void	*wall;
	int		x;
	int		y;
}			t_data;

char	*get_next_line(int fd);

#endif
