/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:03:23 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/25 21:38:53 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

#endif
