/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:54:45 by valecart          #+#    #+#             */
/*   Updated: 2019/10/09 12:47:39 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

int		is_ok(t_stack *a, t_stack *b)
{
	size_t		i;

	i = -1;
	if (b->sp != 0)
		return (-1);
	while (++i < a->sp - 1)
		if (a->stack[i] <= a->stack[i + 1])
			return (-1);
	return (1);
}

int		is_only_one(t_stack *a)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 1;
	while (i < a->sp - 1)
	{
		while (j < a->sp)
		{
			if (a->stack[i] == a->stack[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int		parsing_digit(int n, char **av, t_stack *stack)
{
	int			i;
	int			j;
	long int	tmp;

	i = n - 1;
	j = 0;
	while (i >= 0)
	{
		while (av[i][j])
		{
			if (j == 0)
				if (av[i][j] == '-' || av[i][j] == '+')
					j++;
			if (ft_isdigit(av[i][j]) == 0)
				return (-1);
			j++;
		}
		if ((tmp = ft_atoi(av[i])) > 2147483647 || tmp < -2147483648)
			return (-1);
		stack->stack[stack->sp++] = ft_atoi(av[i]);
		j = 0;
		i--;
	}
	stack->size = n;
	return (1);
}

int		get_instructions_next(char **line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(*line, "pa") == 0)
		push_stack(b, a);
	else if (ft_strcmp(*line, "pb") == 0)
		push_stack(a, b);
	else if (ft_strcmp(*line, "ra") == 0)
		rotate_stack(a);
	else if (ft_strcmp(*line, "rb") == 0)
		rotate_stack(b);
	else if (ft_strcmp(*line, "rr") == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (ft_strcmp(*line, "rra") == 0)
		rev_rotate_stack(a);
	else if (ft_strcmp(*line, "rrb") == 0)
		rev_rotate_stack(b);
	else if (ft_strcmp(*line, "rrr") == 0)
	{
		rev_rotate_stack(a);
		rev_rotate_stack(b);
	}
	else
		return (0);
	return (1);
}

int		get_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
			swap_stack(a);
		else if (ft_strcmp(line, "sb") == 0)
			swap_stack(b);
		else if (ft_strcmp(line, "ss") == 0)
		{
			swap_stack(a);
			swap_stack(b);
		}
		else
		{
			if (get_instructions_next(&line, a, b) != 1)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
	}
	return (1);
}
