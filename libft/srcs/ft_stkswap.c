/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:47:40 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 17:52:40 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_stkswap(t_dlist **stk)
{
	t_dlist	*prev;

	prev = (*stk)->prev;
	if (!stk || !(*stk) || !(*stk)->prev)
		return ;
	(*stk)->next = (*stk)->prev;
	(*stk)->prev = (*stk)->prev->prev;
	if (prev->prev)
		prev->prev->next = (*stk);
	(*stk)->prev->next = NULL;
	*stk = prev;
}
