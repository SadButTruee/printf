/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:05:26 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/28 19:54:06 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pechat_uint(char *str, t_flagi flagi)
{
	int	c;

	c = 0;
	if (flagi.tochnost >= 0)
		c += ft_printf3_shirina(flagi.tochnost - 1, ft_strlen(str) - 1, 1);
	c += ft_putsp(str, ft_strlen(str));
	return (c);
}

static int	ft_put_uint(char *str, t_flagi flagi)
{
	int	count;

	count = 0;
	if (flagi.minus == 1)
		count += ft_pechat_uint(str, flagi);
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
		count += ft_pechat_uint(str, flagi);
	return (count);
}

int	ft_printf3_unsigint (unsigned int number, t_flagi flagi)
{
	int		count;
	char	*str;

	count = 0;
	if (flagi.tochnost == 0 && number == 0)
	{
		count += ft_printf3_shirina(flagi.shirina, 0, 0);
		return (count);
	}
	str = ft_u_itoa(number);
	count = ft_put_uint(str, flagi);
	free(str);
	return (count);
}
