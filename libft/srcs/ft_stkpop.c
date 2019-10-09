/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:06:43 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/02 18:40:45 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_stkpop(t_dlist **stk)
{
	void	*k;
	t_dlist	*prev;

	if (!stk || !*stk)
		return (NULL);
	k = (*stk)->content;
	prev = (*stk)->prev;
	ft_dlstdel(stk, free);
	*stk = prev;
	return (k);
}
