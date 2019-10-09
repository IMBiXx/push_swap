/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_csr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:59:02 by valecart          #+#    #+#             */
/*   Updated: 2019/05/05 23:35:32 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		put_c(t_conv_spec *cs, va_list arg)
{
	char			c;

	c = (char)va_arg(arg, int);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0))
		ft_putnchar(' ', cs->field - 1);
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0)
		ft_putnchar('0', cs->field - 1);
	ft_putchar(c);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - 1);
	return (ft_max(1, cs->field));
}

int		put_s(t_conv_spec *cs, va_list arg)
{
	size_t			str_size;
	char			*s;
	unsigned int	n_print;

	n_print = 0;
	s = va_arg(arg, char *);
	str_size = s ? ft_strlen(s) : 6;
	if (cs->precision >= 0 && cs->precision < (int)str_size)
		n_print = cs->precision;
	else
		n_print = str_size;
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0))
		ft_putnchar(' ', cs->field - n_print);
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0)
		ft_putnchar('0', cs->field - n_print);
	if (cs->precision != 0)
		ft_putnstr(s ? s : "(null)", n_print);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - n_print);
	return (ft_max(n_print, cs->field));
}

int		put_r(t_conv_spec *cs, va_list arg)
{
	size_t			str_size;
	char			*r;
	unsigned int	n_print;

	n_print = 0;
	r = va_arg(arg, char *);
	str_size = r ? ft_strlen(r) : 6;
	if (cs->precision >= 0 && cs->precision < (int)str_size)
		n_print = cs->precision;
	else
		n_print = str_size;
	if (!(cs->flags & FLAG_M))
		ft_putnchar(' ', cs->field - n_print);
	if (cs->precision != 0)
		putstr_r(r ? r : "(null)", n_print);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - n_print);
	return (ft_max(n_print, cs->field));
}
