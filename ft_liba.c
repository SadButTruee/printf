/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:44:26 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/27 19:39:44 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	size_t	s;
	char	*s2;

	s = ft_strlen(s1);
	s2 = malloc(s + 1);
	if (s2 == NULL)
		return (NULL);
	s = 0;
	while (s1[s] != '\0')
	{
		s2[s] = s1[s];
		s++;
	}
	s2[s] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != 0)
	{
		c++;
	}
	return (c);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (7);
	else
		return (0);
}

int	ft_putsp(char *str, int s)
{
	int	i;

	i = 0;
	while (str[i] && i < s)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
