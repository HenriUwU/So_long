/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:15:50 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/27 19:17:14 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_data data)
{
	if (data.mapping[(data.py / 64) - 1][data.px / 64] != '1')
		return (1);
	return (0);
}

int	can_move2(t_data data)
{
	if (data.mapping[(data.py / 64) + 1][data.px / 64] != '1')
		return (1);
	return (0);
}

int	can_move3(t_data data)
{
	if (data.mapping[data.py / 64][(data.px / 64) + 1] != '1')
		return (1);
	return (0);
}

int	can_move4(t_data data)
{
	if (data.mapping[data.py / 64][(data.px / 64) - 1] != '1')
		return (1);
	return (0);
}
