/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstkswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:45:15 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/02 19:04:51 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_sstkswap(t_sstack *stk)
{
	if (stk->sp > 1)
	{
		stk->stack[stk->sp - 1] ^= stk->stack[stk->sp - 2];
		stk->stack[stk->sp - 2] ^= stk->stack[stk->sp - 1];
		stk->stack[stk->sp - 1] ^= stk->stack[stk->sp - 2];
	}
}
