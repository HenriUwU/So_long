/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaupp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:33:21 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/18 13:42:29 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaupp(unsigned int n)
{
	int			count;
	const char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		count = ft_hexaupp(n / 16);
	}
	n %= 16;
	count += ft_putcharupp(base[n]);
	return (count);
}
