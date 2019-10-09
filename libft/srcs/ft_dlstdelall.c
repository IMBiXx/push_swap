/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:36:22 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/02 18:39:27 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstdelall(t_dlist **lst, void (*del)(void *))
{
	t_dlist *l;

	if (!lst || !*lst)
		return ;
	l = (*lst)->next;
	while (l)
	{
		ft_dlstdel(&l, del);
		l = (*lst)->next;
	}
	*lst = NULL;
}
