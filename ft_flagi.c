/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:30:20 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/28 16:39:47 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf3_shirina(int shirina, int minus, int nol)
{
	int	count;

	count = 0;
	while (shirina > minus)
	{
		if (nol)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		shirina--;
		count++;
	}
	return (count);
}

t_flagi	ft_flag_digit(char c, t_flagi flagi)
{
	if (flagi.zvezd == 1)
		flagi.shirina = 0;
	flagi.shirina = (flagi.shirina * 10) + (c - 48);
	return (flagi);
}

t_flagi	ft_flag_minus(t_flagi flagi)
{
	flagi.minus = 1;
	flagi.nol = 0;
	return (flagi);
}

int	ft_flag_tochnost(const char *str, int start, t_flagi *flagi, va_list spis)
{
	int	i;

	i = start;
	i = i + 1;
	if (str[i] == '*')
	{
		flagi->tochnost = va_arg(spis, int);
		i = i + 1;
	}
	else
	{
		flagi->tochnost = 0;
		while (ft_isdigit(str[i]))
		{
			flagi->tochnost = (flagi->tochnost * 10) + (str[i] - 48);
			i = i + 1;
		}
	}
	return (i);
}

t_flagi	ft_flag_shirina(va_list spis, t_flagi flagi)
{
	flagi.zvezd = 1;
	flagi.shirina = va_arg(spis, int);
	if (flagi.shirina < 0)
	{
		flagi.minus = 1;
		flagi.shirina *= -1;
		flagi.nol = 0;
	}
	return (flagi);
}
