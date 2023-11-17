/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:01:40 by dquitari          #+#    #+#             */
/*   Updated: 2023/09/11 09:01:41 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_list1
{
	long	min;
	long	max;
	
}	t_mm;

//stack functions
void    stacks_move_initializer(t_int_list **stack_a, t_int_list **stack_b);
void	ft_s(t_int_list **stack);
void	ft_r(t_int_list **stack);
void	ft_rev_r(t_int_list **stack);
void	ft_p(t_int_list **start, t_int_list **finish);
void	ft_sa(t_int_list **stack_a, t_int_list **stack_b);
void	ft_sb(t_int_list **stack_a, t_int_list **stack_b);
void	ft_ss(t_int_list **stack_a, t_int_list **stack_b);
void	ft_ra(t_int_list **stack_a, t_int_list **stack_b);
void	ft_rb(t_int_list **stack_a, t_int_list **stack_b);
void	ft_rr(t_int_list **stack_a, t_int_list **stack_b);
void	ft_rra(t_int_list **stack_a, t_int_list **stack_b);
void	ft_rrb(t_int_list **stack_a, t_int_list **stack_b);
void	ft_rrr(t_int_list **stack_a, t_int_list **stack_b);
void	ft_pa(t_int_list **stack_a, t_int_list **stack_b);
void	ft_pb(t_int_list **stack_a, t_int_list **stack_b);

//auxiliary printer functions (only for evaluation))
void	stack_printer(t_int_list *stack);
void	stacks_printer(t_int_list *stack_a, t_int_list *stack_b);
void	stack_move_printer(t_int_list *stack);
void	stacks_move_printer(t_int_list *stack_a, t_int_list *stack_b);

//input tests
int	error_test(int argc, char **argv, t_int_list **stack_a);

//small sorters
void	two_sorter(t_int_list **stack, t_int_list **ignored);
void    three_sorter(t_int_list **stack, t_int_list **ignored);

//main sorter
void	final_sorter(t_int_list **stack_a, t_int_list **stack_b);

#endif
