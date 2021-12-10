/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3_adres.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:21:36 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/30 10:02:33 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pechat(char *adres, t_flagi flagi)
{
	int	count;

	count = 0;
	count += ft_putsp("0x", 2);
	if (flagi.tochnost >= 0)
	{
		count += ft_printf3_shirina(flagi.shirina, ft_strlen(adres), 1);
		count += ft_putsp(adres, flagi.tochnost);
	}
	else
		count += ft_putsp(adres, ft_strlen(adres));
	return (count);
}

char	*ft_base(unsigned long long number, int base, int count, char *str)
{
	while (number != 0)
	{
		if ((number % base) < 10)
			str[count - 1] = (number % base) + 48;
		else
			str[count - 1] = (number % base) + 55;
		number /= base;
		count--;
	}
	return (str);
}

char	*ft_utl_base(unsigned long long number, int base)
{
	unsigned long long	temp;
	int					count;
	char				*str;

	temp = number;
	str = 0;
	count = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= base;
		count++;
	}
	str = malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	str = ft_base(temp, base, count, str);
	return (str);
}

int	ft_printf3_adres(unsigned long long num, t_flagi flagi)
{
	int		count;
	char	*p;

	count = 0;
	if (flagi.tochnost == 0 && !num)
	{
		count += ft_printf3_shirina(flagi.shirina - 2, 0, 0);
		count += ft_putsp("0x", 2);
		return (count);
	}
	p = ft_utl_base(num, 16);
	p = ft_zamenaregistra(p);
	if ((size_t)flagi.tochnost < ft_strlen(p))
		flagi.tochnost = ft_strlen(p);
	if (flagi.minus == 1)
		count += ft_pechat(p, flagi);
	count += ft_printf3_shirina(flagi.shirina, ft_strlen(p) + 2, 0);
	if (flagi.minus == 0)
		count += ft_pechat(p, flagi);
	free(p);
	return (count);
}
