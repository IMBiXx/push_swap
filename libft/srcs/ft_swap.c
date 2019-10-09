/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:24:33 by tpotier           #+#    #+#             */
/*   Updated: 2019/05/05 20:45:13 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t s)
{
	if (a != b)
		while (s-- > 0)
		{
			((unsigned char *)a)[s] ^= ((unsigned char *)b)[s];
			((unsigned char *)b)[s] ^= ((unsigned char *)a)[s];
			((unsigned char *)a)[s] ^= ((unsigned char *)b)[s];
		}
}
