/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:34:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 23:28:06 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_put_conv_spec(t_conv_spec *cspec, va_list arg, int *c)
{
	if (cspec->type == 'd' || cspec->type == 'i' || cspec->type == 'D')
		*c += put_d(cspec, arg);
	if (cspec->type == 'u' || cspec->type == 'U')
		*c += put_u(cspec, arg);
	if (cspec->type == 'p')
		*c += put_p(cspec, arg);
	if (cspec->type == 's')
		*c += put_s(cspec, arg);
	if (cspec->type == 'f' || cspec->type == 'F')
		*c += put_f(cspec, arg);
	if (cspec->type == 'o' || cspec->type == 'O')
		*c += put_o(cspec, arg);
	if (cspec->type == 'c')
		*c += put_c(cspec, arg);
	if (cspec->type == 'x' || cspec->type == 'X')
		*c += put_x(cspec, arg);
	if (cspec->type == 'k' || cspec->type == 'K')
		*c += put_k(cspec, arg);
	if (cspec->type == 'b' || cspec->type == 'B')
		*c += put_b(cspec, arg);
	if (cspec->type == 'r')
		*c += put_r(cspec, arg);
	if (!ft_strchr(CONV_CHARS, cspec->type))
		*c += put_other(cspec);
}
