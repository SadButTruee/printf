/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:15:30 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/28 16:05:38 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf3_char(char c, t_flagi flagi)
{
	int	count;

	if (flagi.minus == 1)
		write(1, &c, 1);
	count = ft_printf3_shirina(flagi.shirina, 1, 0);
	if (flagi.minus == 0)
		write(1, &c, 1);
	return (count + 1);
}
