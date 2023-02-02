/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:17:48 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/18 13:43:19 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalow(unsigned int n)
{
	int			count;
	const char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		count = ft_hexalow(n / 16);
	}
	n %= 16;
	count += ft_putchar_count(base[n]);
	return (count);
}
