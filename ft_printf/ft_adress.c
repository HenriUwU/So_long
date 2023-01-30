/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:17 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/19 14:38:08 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long n, const char *base)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count = ft_putnbr_base(n / 16, base);
	}
	n %= 16;
	count += ft_putchar_count(base[n]);
	return (count);
}

int	ft_adress(unsigned long n)
{
	int	count;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr_count("0x");
	count = ft_putnbr_base(n, "0123456789abcdef");
	return (count + 2);
}
