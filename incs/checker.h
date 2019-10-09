/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:55:09 by valecart          #+#    #+#             */
/*   Updated: 2019/10/09 12:19:49 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

typedef struct		s_stack
{
	int				*stack;
	size_t			sp;
	int				med;
	size_t			size;
}					t_stack;

int		ft_error(char const *str);
int			ft_stack_pop(t_stack *stack);
int			ft_stack_push(t_stack *stack, int n);
int		parsing_digit(int n, char **av, t_stack *stack);
int		is_ok(t_stack *a, t_stack *b);
int		get_instructions(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
int		push_stack(t_stack *one, t_stack *two);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	rev_rotate_stack(t_stack *stack);
int		is_only_one(t_stack *a);

#endif
