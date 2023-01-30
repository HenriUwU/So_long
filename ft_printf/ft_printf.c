/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:39:43 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/19 17:12:35 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conditions(int count, char c, va_list args)
{
	if (c == 'i' || c == 'd')
		count = ft_putnbr_count(va_arg(args, int));
	else if (c == 'c')
		count = ft_putchar_count(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr_count(va_arg(args, char *));
	else if (c == 'p')
		count = ft_adress(va_arg(args, unsigned long));
	else if (c == 'u')
		count = ft_putuint_count(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_hexalow(va_arg(args, unsigned int));
	else if (c == 'X')
		count = ft_hexaupp(va_arg(args, unsigned int));
	else if (c == '%')
		count = ft_putchar_count('%');
	else
	{
		count = ft_putchar_count('%');
		count += ft_putchar_count(c);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] && i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			count += ft_conditions(count, str[++i], args);
			i++;
		}
		else
		{
			count += ft_putchar_count(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
