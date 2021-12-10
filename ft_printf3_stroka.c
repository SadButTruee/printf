/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3_stroka.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:29:02 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/28 17:03:19 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pechat(char *str, t_flagi flagi)
{
	int	count;

	count = 0;
	if (flagi.tochnost >= 0)
		count += ft_putsp(str, flagi.tochnost);
	else
		count += ft_putsp(str, ft_strlen(str));
	return (count);
}

int	ft_printf3_stroka(char *str, t_flagi flagi)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flagi.tochnost >= 0 && (size_t)flagi.tochnost > ft_strlen(str))
		flagi.tochnost = ft_strlen(str);
	if (flagi.minus == 1)
		count += ft_pechat(str, flagi);
	if (flagi.tochnost >= 0)
		count += ft_printf3_shirina(flagi.shirina, flagi.tochnost, 0);
	else
		count += ft_printf3_shirina(flagi.shirina, ft_strlen(str), 0);
	if (flagi.minus == 0)
		count += ft_pechat(str, flagi);
	return (count);
}
