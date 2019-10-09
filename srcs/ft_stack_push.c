/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:14:28 by valecart          #+#    #+#             */
/*   Updated: 2019/05/17 17:08:54 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_stack_push(t_stack *stack, int n)
{
	if (stack->sp == stack->size)
		return (-1);
	return (stack->stack[++stack->sp] = n);
}
