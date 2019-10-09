/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:43:29 by valecart          #+#    #+#             */
/*   Updated: 2019/07/19 14:15:39 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *stack)
{
	int		i;

	i = stack->sp - 1;
	while (i >= 0)
	{
		ft_putnbr(stack->stack[i]);
		i--;
		if (i >= 0)
			ft_putstr(", ");
		else
			ft_putendl(".");
	}
}

int		push_stack(t_stack *one, t_stack *two)
{
	if (one->sp < 1)
		return (0);
	two->stack[two->sp] = ft_stack_pop(one);
	two->sp++;
	return (1);
}

void	swap_stack(t_stack *stack)
{
	int		tmp;

	if (stack->sp < 2)
		return ;
	stack->sp--;
	tmp = stack->stack[stack->sp]; // save top
	stack->stack[stack->sp] = stack->stack[stack->sp - 1]; // place top - 1 au top
	stack->stack[stack->sp - 1] = tmp; // place save dans top - 1
	stack->sp++;
}

void	rotate_stack(t_stack *stack)
{
	int		tmp;
	size_t	i;

	if (stack->sp < 2)
		return ;
	i = stack->sp - 1;
	tmp = stack->stack[stack->sp - 1];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = tmp;
}

void	rev_rotate_stack(t_stack *stack)
{
	int		tmp;
	size_t	i;

	if (stack->sp < 2)
		return ;
	i = 0;
	tmp = stack->stack[0];
	while (i < stack->sp - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = tmp;
}
