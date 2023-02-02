/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:03:50 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/19 15:49:58 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count = ft_putuint_count(n / 10);
	count += ft_putchar_count((n % 10) + '0');
	return (count);
}
