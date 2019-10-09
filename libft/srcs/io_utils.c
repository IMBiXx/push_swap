/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:17 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 23:30:01 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		put_special(long double f)
{
	if (f == INFP || f == INFN)
		ft_putstr("inf");
	if (f != f)
		ft_putstr("nan");
}

void		putstr_r(char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (s[i] && i < size)
	{
		if (ft_isprint(s[i]) == 1)
			ft_putchar(s[i]);
		else
		{
			ft_putstr("\\x");
			ft_putchar("0123456789abcdef"[(unsigned char)(s[i]) / 16]);
			ft_putchar("0123456789abcdef"[(unsigned char)(s[i]) % 16]);
		}
		i++;
	}
}

void		ft_putl_zer_base(long long n, int zer, char f_sgn, int b)
{
	unsigned long long	numb;
	const char			digits[] = "0123456789abcdef";

	if (n < 0)
		ft_putchar('-');
	else if (f_sgn & (FLAG_P | FLAG_SP))
		ft_putchar(f_sgn & FLAG_P ? '+' : ' ');
	ft_putnchar('0', zer);
	numb = (n < 0) ? -n : n;
	if (numb > (unsigned int)(b - 1))
		ft_putl_zer_base(numb / b, 0, 0, b);
	ft_putchar(digits[numb % b]);
}

void		ft_putf_zer_base(long double n, int zer, char f_sgn, int b)
{
	long double		numb;
	const char		digits[] = "0123456789abcdef";

	if (is_neg(n))
		ft_putchar('-');
	else if (f_sgn & (FLAG_P | FLAG_SP))
		ft_putchar(f_sgn & FLAG_P ? '+' : ' ');
	if (is_special(n))
		put_special(n);
	else
	{
		ft_putnchar('0', zer);
		numb = (is_neg(n)) ? -n : n;
		if (numb > (b - 1))
			ft_putf_zer_base(numb / b, 0, 0, b);
		ft_putchar(digits[(long long)numb % b]);
	}
}

void		ft_putl_zer_base_u(unsigned long long n, int zer, int cas, int b)
{
	const char			digits[] = "0123456789abcdef";

	ft_putnchar('0', zer);
	if (n > (unsigned int)(b - 1))
		ft_putl_zer_base_u(n / b, 0, cas, b);
	ft_putchar(cas ? ft_toupper(digits[n % b]) : digits[n % b]);
}
