/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:43:57 by valecart          #+#    #+#             */
/*   Updated: 2019/10/09 12:35:57 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_error(char const *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

int			ft_stack_pop(t_stack *stack)
{
	if (stack->sp == 0)
		return (-1);
	return (stack->stack[--stack->sp]);
}

int			ft_stack_push(t_stack *stack, int n)
{
	if (stack->sp == stack->size)
		return (-1);
	return (stack->stack[++stack->sp] = n);
}
