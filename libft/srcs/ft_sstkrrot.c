/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstkrrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:55:29 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 15:30:30 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_sstkrrot(t_sstack *stk)
{
	int	tmp;

	if (!stk->sp)
		return ;
	tmp = stk->stack[0];
	ft_memmove(stk->stack, &(stk->stack[1]), sizeof(int) * (stk->sp - 1));
	stk->stack[stk->sp - 1] = tmp;
}
