/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdisp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:45:35 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/02 18:06:08 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstdisp(t_dlist *stk, void (*dsp)(void *))
{
	if (!stk)
		return ;
	while (stk->prev)
		stk = stk->prev;
	while (stk)
	{
		dsp(stk->content);
		stk = stk->next;
	}
}
