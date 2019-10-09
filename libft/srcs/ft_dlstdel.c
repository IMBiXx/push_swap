/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:26:06 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 19:13:26 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstdel(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*t;

	if (!lst || !*lst)
		return ;
	if ((*lst)->prev)
		(*lst)->prev->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	if (del)
		del((*lst)->content);
	t = (*lst)->prev;
	free(*lst);
	*lst = t;
}
