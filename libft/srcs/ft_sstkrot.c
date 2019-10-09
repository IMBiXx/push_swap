/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstkrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:52:07 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 16:18:05 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_sstkrot(t_sstack *stk)
{
	int	tmp;

	if (!stk->sp)
		return ;
	tmp = stk->stack[stk->sp - 1];
	ft_memmove(&(stk->stack[1]), stk->stack, sizeof(int) * (stk->sp - 1));
	stk->stack[0] = tmp;
}
