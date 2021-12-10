/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:02:42 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/30 10:12:18 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specpre(int c)
{
	char	*specpre;

	specpre = "cCspdDiuUxX%";
	while (*specpre)
	{
		if (*specpre == c)
			return (c);
		specpre++;
	}
	return (0);
}

int	ft_flagi(int c)
{
	char	*flagi;

	flagi = ".*0- ";
	while (*flagi)
	{
		if (*flagi == c)
			return (c);
		flagi++;
	}
	return (0);
}

void	ft_probel(int i, const char *str)
{
	if ((str[i - 1] != ' ') && (str[i + 1] != ' '))
		write(1, " ", 1);
	if ((str[i + 1] == 'i') || (str[i + 1] == 'u') || (str[i + 1] == 'd'))
		write(1, " ", 1);
	if ((str[i + 1] == 'U') || (str[i + 1] == 'D'))
		write(1, " ", 1);
}

int	ft_printf3_procent(t_flagi flagi)
{
	int	count;

	count = 0;
	if (flagi.minus == 1)
		count += ft_putsp("%", 1);
	count += ft_printf3_shirina(flagi.shirina, 1, flagi.nol);
	if (flagi.minus == 0)
		count += ft_putsp("%", 1);
	return (count);
}

char	*ft_zamenaregistra(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
