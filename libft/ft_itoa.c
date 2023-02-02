/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:48:33 by hsebille          #+#    #+#             */
/*   Updated: 2022/10/07 15:15:16 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*loop(int n, int counter, char *nstr)
{
	if (n < 0)
	{
		n *= -1;
		while (counter > 0)
		{
			nstr[counter - 1] = n % 10 + '0';
			n = n / 10;
			counter--;
		}
		nstr[counter] = '-';
	}
	else if (n >= 0)
	{
		while (counter > 0)
		{
			nstr[counter - 1] = n % 10 + '0';
			n = n / 10;
			counter--;
		}
	}
	nstr[ft_strlen(nstr)] = '\0';
	return (nstr);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*nstr;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	counter = ft_intlen(n);
	nstr = ft_calloc(counter + 1, sizeof(char));
	if (nstr == NULL)
		return (NULL);
	loop(n, counter, nstr);
	return (nstr);
}
