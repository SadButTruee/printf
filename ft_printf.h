/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:28:33 by rtracee           #+#    #+#             */
/*   Updated: 2021/05/27 20:15:54 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define UI unsigned int
# define CC const char

typedef struct s_flagi
{
	int	shirina;
	int	zvezd;
	int	type;
	int	minus;
	int	nol;
	int	tochnost;
}			t_flagi;

char	*ft_zamenaregistra(char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	ft_probel(int i, const char *str);
int		ft_putsp(char *str, int s);
void	ft_putstr(char *s);

int		ft_printf(const char *str, ...);
int		ft_specpre(int c);
char	*ft_u_itoa(unsigned int n);
char	*ft_u_itoa(unsigned int n);
int		ft_flagi(int c);
int		ft_printf3_char(char c, t_flagi flagi);
int		ft_printf3_procent(t_flagi flagi);
int		ft_printf3_adres(unsigned long long num, t_flagi flagi);
int		ft_printf3_stroka(char *str, t_flagi flagi);
int		ft_printf3_int(int i, t_flagi flagi);
int		ft_printf3_shest(unsigned int number, int registr, t_flagi flagi);
int		ft_printf3_unsigint (unsigned int number, t_flagi flagi);
int		ft_printf3_shirina(int shirina, int minus, int nol);
char	*ft_utl_base(unsigned long long number, int sshis);
char	*ft_base(unsigned long long number, int base, int count, char *str);
t_flagi	ft_flag_digit(char c, t_flagi flagi);
t_flagi	ft_flag_minus(t_flagi flagi);
t_flagi	ft_flag_shirina(va_list spis, t_flagi flagi);
int		ft_flag_tochnost(CC *str, int start, t_flagi *flagi, va_list spis);
#endif