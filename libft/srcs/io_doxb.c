/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_doxb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:04:50 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 23:35:42 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			put_d(t_conv_spec *cs, va_list arg)
{
	intmax_t		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	if (cs->type == 'D')
		cs->modifier = MOD_L;
	d = get_arg_int(cs, arg);
	num_size = (cs->precision || d) ? ft_nlen_base(d, 10) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (d < 0 || cs->flags & FLAG_P
			|| cs->flags & FLAG_SP ? 1 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		ft_putnchar(' ', cs->field - num_size);
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		n_zeroes += cs->field - num_size;
	if (cs->precision || d)
		ft_putl_zer_base(d, n_zeroes, cs->flags, 10);
	else if (cs->flags & (FLAG_P | FLAG_SP))
		ft_putchar(cs->flags & FLAG_P ? '+' : ' ');
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (ft_max(num_size, cs->field));
}

int			put_u(t_conv_spec *cs, va_list arg)
{
	uintmax_t		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	if (cs->type == 'U')
		cs->modifier = MOD_L;
	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? ft_nlen_base(d, 10) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes;
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		ft_putnchar(' ', cs->field - num_size);
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		n_zeroes += cs->field - num_size;
	if (cs->precision || d)
		ft_putl_zer_base_u(d, n_zeroes, 0, 10);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (ft_max(num_size, cs->field));
}

int			put_x(t_conv_spec *cs, va_list arg)
{
	uintmax_t		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? ft_nlen_base(d, 16) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (cs->flags & FLAG_SH && d ? 2 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		ft_putnchar(' ', cs->field - num_size);
	if (cs->flags & FLAG_SH && d)
		ft_putstr(cs->type == 'X' ? "0X" : "0x");
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		ft_putnchar('0', cs->field - num_size);
	if (cs->precision || d)
		ft_putl_zer_base_u(d, n_zeroes, cs->type == 'X', 16);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (ft_max(num_size, cs->field));
}

int			put_o(t_conv_spec *cs, va_list arg)
{
	uintmax_t		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	if (cs->type == 'O')
		cs->modifier = MOD_L;
	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? ft_nlen_base(d, 8) : 0;
	n_zeroes = (cs->precision > (int)num_size ? cs->precision - num_size : 0);
	num_size += n_zeroes
		+ (cs->flags & FLAG_SH && (!cs->precision || d) && !n_zeroes ? 1 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		ft_putnchar(' ', cs->field - num_size);
	if (cs->flags & FLAG_SH && (!cs->precision || d) && !n_zeroes)
		ft_putchar('0');
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		ft_putnchar('0', cs->field - num_size);
	if (cs->precision || d)
		ft_putl_zer_base_u(d, n_zeroes, 0, 8);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (ft_max(num_size, cs->field));
}

int			put_b(t_conv_spec *cs, va_list arg)
{
	uintmax_t		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? ft_nlen_base(d, 2) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (cs->flags & FLAG_SH && d ? 2 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		ft_putnchar(' ', cs->field - num_size);
	if (cs->flags & FLAG_SH && d)
		ft_putstr(cs->type == 'B' ? "0B" : "0b");
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		ft_putnchar('0', cs->field - num_size);
	ft_putl_zer_base_u(d, n_zeroes, 0, 2);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (ft_max(num_size, cs->field));
}
