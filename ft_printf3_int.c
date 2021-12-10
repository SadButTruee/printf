/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:36:31 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/26 15:02:28 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pechat(char *str, int num, t_flagi flagi)
{
	int	count;

	count = 0;
	if (flagi.tochnost >= 0 && num < 0 && num != -2147483648)
		write(1, "-", 1);
	if (flagi.tochnost >= 0)
		count += ft_printf3_shirina(flagi.tochnost - 1, ft_strlen(str) - 1, 1);
	count += ft_putsp(str, ft_strlen(str));
	return (count);
}

static int	ft_int_flagi(char *str, int num, t_flagi flagi)
{
	int	count;

	count = 0;
	if (flagi.minus == 1)
		count += ft_pechat(str, num, flagi);
	if (flagi.tochnost >= 0 && (size_t)flagi.tochnost < ft_strlen(str))
		flagi.tochnost = ft_strlen(str);
	if (flagi.tochnost >= 0)
	{
		flagi.shirina -= flagi.tochnost;
		count += ft_printf3_shirina(flagi.shirina, 0, 0);
	}
	else
		count += ft_printf3_shirina(flagi.shirina, ft_strlen(str), flagi.nol);
	if (flagi.minus == 0)
		count += ft_pechat(str, num, flagi);
	return (count);
}

int	ft_printf3_int(int i, t_flagi flagi)
{
	int		count;
	int		num;
	char	*str;

	count = 0;
	num = i;
	if (flagi.tochnost == 0 && i == 0)
	{
		count += ft_printf3_shirina(flagi.shirina, 0, 0);
		return (count);
	}
	if (i < 0 && (flagi.tochnost >= 0 || flagi.nol == 1) && i != -2147483648)
	{
		if (flagi.tochnost <= -1 && flagi.nol == 1)
			write(1, "-", 1);
		i *= -1;
		flagi.nol = 1;
		flagi.shirina--;
		count++;
	}
	str = ft_itoa(i);
	count += ft_int_flagi(str, num, flagi);
	free(str);
	return (count);
}
