/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_k.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 07:55:18 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 23:37:47 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		put_color(t_style style)
{
	size_t	len;
	int		t;

	len = 0;
	t = style >> 16 & 0xff;
	len += ft_nlen_base(t, 10);
	ft_putnbr(t);
	ft_putchar(';');
	t = style >> 8 & 0xff;
	len += ft_nlen_base(t, 10);
	ft_putnbr(t);
	ft_putchar(';');
	t = style & 0xff;
	len += ft_nlen_base(t, 10);
	ft_putnbr(t);
	return (len);
}

size_t		put_style(t_style style)
{
	size_t	len;

	len = 0;
	len += style & K_M_UNDER ? 4 : 0;
	if (style & K_M_UNDER)
		ft_putstr("\x1B[4m");
	len += style & K_M_NUNDER ? 5 : 0;
	if (style & K_M_NUNDER)
		ft_putstr("\x1B[24m");
	len += style & K_M_BOLD ? 4 : 0;
	if (style & K_M_BOLD)
		ft_putstr("\x1B[1m");
	len += style & K_M_NBOLD ? 5 : 0;
	if (style & K_M_NBOLD)
		ft_putstr("\x1B[21m");
	len += style & K_M_ITAL ? 4 : 0;
	if (style & K_M_ITAL)
		ft_putstr("\x1B[3m");
	len += style & K_M_NITAL ? 5 : 0;
	if (style & K_M_NITAL)
		ft_putstr("\x1B[23m");
	return (len);
}

int			put_k(t_conv_spec *cs, va_list arg)
{
	size_t	len;
	t_style	style;

	if (cs->type == 'K')
	{
		ft_putstr("\x1B[0m");
		return (4);
	}
	style = va_arg(arg, t_style);
	len = put_style(style);
	ft_putstr("\x1B[48;2;");
	len += 10 + put_color(style >> K_BG_SHIFT & K_COL_MSK);
	ft_putchar('m');
	ft_putstr("\x1B[38;2;");
	len += 10 + put_color(style & K_COL_MSK);
	ft_putchar('m');
	return (len);
}
