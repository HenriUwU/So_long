/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:17 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/14 17:02:31 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long n, char *base)
{
	if (n > 15)
	{
		ft_putnbr_base(n / 16, base);
	}
	n %= 16;
	ft_putchar_fd(base[n], 1);
}
