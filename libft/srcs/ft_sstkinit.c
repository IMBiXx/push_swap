/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstkinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:32:30 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/02 19:49:18 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sstack			*ft_sstkinit(size_t s)
{
	t_sstack	*stk;

	if (!(stk = (t_sstack *)malloc(sizeof(*stk))))
		return (NULL);
	if (!(stk->stack = (int *)ft_memalloc(s * sizeof(int))))
		return (NULL);
	stk->sp = 0;
	stk->size = s;
	return (stk);
}
