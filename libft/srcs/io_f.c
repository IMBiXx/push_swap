/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:53:35 by valecart          #+#    #+#             */
/*   Updated: 2019/05/05 23:37:33 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		put_f_round(t_conv_spec *cs, long double f)
{
	long double	tmp;
	int			n;

	if (is_special(f))
		return (f);
	n = 0;
	tmp = f * (f >= 0 ? 1 : -1);
	while (n++ < cs->precision)
		tmp = 10 * (tmp - (long long)tmp);
	tmp -= (long long)tmp;
	if (tmp >= 0.5)
	{
		tmp = 1;
		while (n-- > 1)
			tmp /= 10;
		f += tmp * (f >= 0 ? 1 : -1);
	}
	return (f);
}

void			put_f_decimal(t_conv_spec *cs, long double f)
{
	int	n;

	if (is_special(f))
		return ;
	f *= f >= 0 ? 1 : -1;
	n = 0;
	ft_putchar('.');
	while (n++ < cs->precision)
	{
		ft_putchar('0' + (long long)(f *= 10) % 10);
		f -= (long long)f;
	}
}

int				put_f(t_conv_spec *cs, va_list arg)
{
	long double		f;
	size_t			n_size;
	int				n_zeroes;

	if (cs->type == 'F')
		cs->modifier = MOD_L;
	f = get_arg_float(cs, arg);
	n_size = 3;
	if (!is_special(f))
		n_size = ft_nlen_base((long long)f, 10) + cs->precision
			+ (cs->precision > 0 ? 1 : 0);
	n_size += (is_neg(f) || cs->flags & FLAG_P || cs->flags & FLAG_SP ? 1 : 0);
	n_zeroes = cs->field - n_size - (!is_special(f) && (cs->precision > 0
				|| (cs->precision == 0 && cs->flags & FLAG_SH)) ? 1 : 0);
	n_zeroes = n_zeroes > 0 ? n_zeroes : 0;
	n_size += n_zeroes;
	if (!(cs->flags & FLAG_M) && (!(cs->flags & FLAG_0) || is_special(f)))
		ft_putnchar(' ', n_zeroes);
	f = put_f_round(cs, f);
	ft_putf_zer_base(f, cs->flags & FLAG_M ? 0 : n_zeroes, cs->flags, 10);
	if (cs->precision > 0 || (cs->precision == 0 && cs->flags & FLAG_SH))
		put_f_decimal(cs, f);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', n_zeroes);
	return (ft_max(n_size, cs->field));
}
