/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:54:45 by valecart          #+#    #+#             */
/*   Updated: 2019/07/19 14:59:02 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	if (ac < 2)
		return (0);
	a = (t_stack*)malloc(sizeof(t_stack));
	b = (t_stack*)malloc(sizeof(t_stack));
	a->sp = 0;
	b->sp = 0;
	a->stack = (int*)malloc(sizeof(t_stack) * ac);
	b->stack = (int*)malloc(sizeof(t_stack) * ac);
	if (parsing_digit(ac - 1, av + 1, a) == -1)
		return (ft_error("Error\n"));
	if (is_only_one(a) == -1)
		return (ft_error("Error\n"));
	if (get_instructions(a, b) == -1)
		return (ft_error("Error\n"));
	if (is_ok(a, b) == -1)
	{
		ft_putendl("KO");
		return (0);
	}
	ft_putendl("OK");
	return (0);
}
