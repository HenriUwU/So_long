/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:43:48 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/18 14:21:09 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n)
{
	int	count;
	int	negative;

	count = 0;
	negative = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		negative = ft_putchar_count('-');
		n *= -1;
	}
	if (n > 9)
	{
		count = ft_putnbr_count(n / 10);
	}
	count += ft_putchar_count((n % 10) + '0');
	if (negative == 1)
		return (count + negative);
	return (count);
}
