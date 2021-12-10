/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:51:36 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/28 17:51:16 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_generate(char *nc, long num, int kolvo, int neg)
{
	if (num != 0)
		nc = malloc(sizeof(char) * (kolvo + 1));
	else
		return (nc = ft_strdup("0"));
	if (!nc)
		return (0);
	neg = 0;
	if (num < 0)
	{
		neg++;
		num = -num;
	}
	nc[kolvo] = '\0';
	while (--kolvo)
	{
		nc[kolvo] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		nc[0] = '-';
	else
		nc[0] = (num % 10) + '0';
	return (nc);
}

char	*ft_u_itoa(unsigned int n)
{
	int		kolvo;
	char	*nc;
	long	num;
	int		neg;

	num = n;
	kolvo = 0;
	while (n >= 1)
	{
		kolvo++;
		n /= 10;
	}
	nc = 0;
	neg = 0;
	nc = ft_generate(nc, num, kolvo, neg);
	if (!nc)
		return (0);
	return (nc);
}

static	int	ft_kolvo(int n)
{
	int		i;
	long	s;

	i = 0;
	s = n;
	if (s < 0)
	{
		s *= -1;
		i++;
	}
	while (s >= 10)
	{
		s /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*sar;
	int		a;
	long	b;

	b = n;
	a = ft_kolvo(b);
	sar = malloc(ft_kolvo(b) + 1);
	if (sar == NULL)
		return (NULL);
	if (n < 0)
		sar[0] = '-';
	if (b < 0)
		b = -b;
	sar[a] = '\0';
	a--;
	while (b >= 10)
	{
		sar[a] = b % 10 + 48;
		b /= 10;
		a--;
	}
	sar[a] = b % 10 + 48;
	return (sar);
}
