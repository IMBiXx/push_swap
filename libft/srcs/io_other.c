/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:04:52 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 23:29:43 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			max(int a, int b)
{
	return (a > b ? a : b);
}

int			put_other(t_conv_spec *cs)
{
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0))
		ft_putnchar(' ', cs->field - 1);
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0)
		ft_putnchar('0', cs->field - 1);
	ft_putchar(cs->type);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - 1);
	return (max(1, cs->field));
}
