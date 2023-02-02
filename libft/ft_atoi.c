/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:17:21 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/10 16:06:31 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(int negative, long nb)
{
	int	check;

	check = 2;
	if (nb * negative > 2147483647)
		check = -1;
	if (nb * negative < -2147483648)
		check = 0;
	return (check);
}

int	ft_atoi(const char *nptr)
{	
	int		i;
	long	nb;
	int		negative;

	i = 0;
	negative = 1;
	nb = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		negative *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
		if (ft_overflow(negative, nb) == -1 || ft_overflow(negative, nb) == 0)
			return (ft_overflow(negative, nb));
	}
	return (nb * negative);
}
