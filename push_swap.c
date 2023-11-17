/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:03:18 by dquitari          #+#    #+#             */
/*   Updated: 2023/09/11 09:01:20 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_freer(t_int_list **stack)
{
	t_int_list	*aux;
	t_int_list	*aux2;
	
	while ((*stack)->next != (*stack))
	{
		aux = (*stack);
		while (aux->index < aux->next->index)
			aux = aux->next;
		aux->next = NULL;
		aux2 = aux->prev;
		aux2->next = *stack;
		free(aux);
		aux = aux2;
		//stack_printer(*stack);
	}
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	free(*stack);
}

void	stacks_freer(t_int_list **stack_a, t_int_list **stack_b)
{
	stack_freer(stack_a);
	(void)stack_b;
	//free(stack_a);
	//free(stack_b);
}

int	ft_error()
{
	//stacks_freer(stack_a, stack_b);
	ft_printf("Error\n");
	return (-1);
}

void	sorter_picker(int argc, t_int_list **stack_a, t_int_list **stack_b)
{
	if (argc - 1 == 1)
		stacks_freer(stack_a, stack_b);
	if (argc - 1 == 2)
		two_sorter(stack_a, stack_b);
	if (argc - 1 == 3)
		three_sorter(stack_a, stack_b);
	if (argc - 1 >= 4)
		final_sorter(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_int_list	*stack_a;
	t_int_list	*stack_b;
	int	n;

	n = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (error_test(argc, argv, &stack_a) == -1)
		return (ft_error());
	if (argc == 2)
	{
		free(stack_a);
		free(stack_b);
		return (0);	
	}
	stacks_printer(stack_a, stack_b);
	sorter_picker(argc, &stack_a, &stack_b);
	stacks_printer(stack_a, stack_b);
	stacks_freer(&stack_a, &stack_b);
	return (0);
}
