/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3_shest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:54:57 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/29 15:50:24 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_shest_pechat(char *she, t_flagi flagi)
{
	int	count;

	count = 0;
	if (flagi.tochnost >= 0)
	{
		count += ft_printf3_shirina(flagi.tochnost - 1, ft_strlen(she) - 1, 1);
	}
	count += ft_putsp(she, ft_strlen(she));
	return (count);
}

static int	ft_shest_flagi(char *shest, t_flagi flagi)
{
	int	count;

	count = 0;
	if (flagi.minus == 1)
		count += ft_shest_pechat(shest, flagi);
	if (flagi.tochnost >= 0 && (size_t)flagi.tochnost < ft_strlen(shest))
		flagi.tochnost = ft_strlen(shest);
	if (flagi.tochnost >= 0)
	{
		flagi.shirina -= flagi.tochnost;
		count += ft_printf3_shirina(flagi.shirina, 0, 0);
	}
	else
	{
		count += ft_printf3_shirina(flagi.shirina, ft_strlen(shest), flagi.nol);
	}
	if (flagi.minus == 0)
		count += ft_shest_pechat(shest, flagi);
	return (count);
}

int	ft_printf3_shest(unsigned int number, int registr, t_flagi flagi)
{
	char	*shest;
	int		count;

	count = 0;
	if (flagi.tochnost == 0 && number == 0)
	{
		count += ft_printf3_shirina(flagi.shirina, 0, 0);
		return (count);
	}
	shest = ft_utl_base((unsigned long long)number, 16);
	if (registr == 1)
		shest = ft_zamenaregistra(shest);
	count += ft_shest_flagi(shest, flagi);
	free(shest);
	return (count);
}
