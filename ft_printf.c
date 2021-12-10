/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:26:03 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/23 16:15:44 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flagi	ft_iniflagi(void)
{
	t_flagi	flagi;

	flagi.shirina = 0;
	flagi.zvezd = 0;
	flagi.type = 0;
	flagi.minus = 0;
	flagi.nol = 0;
	flagi.tochnost = -1;
	return (flagi);
}

static int	ft_parseflagi(const char *str, int i, t_flagi *flagi, va_list spis)
{
	while (str[i])
	{
		if (str[i] == ' ')
			ft_probel(i, str);
		if (str[i] == '0' && flagi->shirina == 0 && flagi->minus == 0)
			flagi->nol = 1;
		if (str[i] == '*')
			*flagi = ft_flag_shirina(spis, *flagi);
		if (str[i] == '.')
			i = ft_flag_tochnost(str, i, flagi, spis);
		if (str[i] == '-')
			*flagi = ft_flag_minus(*flagi);
		if (ft_isdigit(str[i]))
			*flagi = ft_flag_digit(str[i], *flagi);
		if (ft_specpre(str[i]))
		{
			flagi->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int	ft_printf3(int c, t_flagi flagi, va_list spis)
{
	int	count;

	count = 0;
	if ((c == 'c') || (c == 'C'))
		count = ft_printf3_char(va_arg(spis, int), flagi);
	else if (c == '%')
		count += ft_printf3_procent(flagi);
	else if (c == 'p')
		count = ft_printf3_adres(va_arg(spis, unsigned long long), flagi);
	else if (c == 's')
		count = ft_printf3_stroka(va_arg(spis, char *), flagi);
	else if ((c == 'i') || (c == 'd') || (c == 'D'))
		count = ft_printf3_int(va_arg(spis, int), flagi);
	else if (c == 'x')
		count += ft_printf3_shest(va_arg(spis, unsigned int), 1, flagi);
	else if (c == 'X')
		count += ft_printf3_shest(va_arg(spis, unsigned int), 0, flagi);
	else if ((c == 'u') || (c == 'U'))
		count += ft_printf3_unsigint((UI)va_arg(spis, UI), flagi);
	return (count);
}

static int	ft_printf2(const char *str, va_list spis, int i, int j)
{
	t_flagi	flagi;

	while (str[i] != 0)
	{
		flagi = ft_iniflagi();
		if (str[i] == '%' && str[i + 1])
		{
			i = ft_parseflagi(str, ++i, &flagi, spis);
			j += ft_printf3((char)flagi.type, flagi, spis);
		}
		else if (str[i] != '%')
			j += write(1, &str[i], 1);
		i++;
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	spis;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(spis, str);
	j += ft_printf2(str, spis, i, j);
	va_end(spis);
	return (j);
}


