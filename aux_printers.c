/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:00:40 by dquitari          #+#    #+#             */
/*   Updated: 2023/09/11 09:00:41 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_printer(t_int_list *stack)
{
	t_int_list	*aux;

	ft_printf("[i]	||	(prev)	(val)	(next)\n");
	aux = stack;
	if (!aux->next)
			ft_printf("[%d]	||	(<- █)	(%d)	(█ ->)\n",aux->index, aux->val);
	else
	{
		ft_printf("[%d]	||	(<- %d)	(%d)	(%d ->)\n",aux->index, aux->prev->val, aux->val, aux->next->val);
		aux = aux->next;
		while (aux->index != 0)
		{
				ft_printf("[%d]	||	(<- %d)	(%d)	(%d ->)\n",aux->index, aux->prev->val, aux->val, aux->next->val);
			aux = aux->next;
		}
	}
	ft_printf("\n");
}

void	stacks_printer(t_int_list *stack_a, t_int_list *stack_b)
{
	if (stack_a)
	{
		ft_printf("STACK A:\n");
		stack_printer(stack_a);
	}
	if (stack_b)
	{
		ft_printf("STACK B:\n");
		stack_printer(stack_b);
	}
}

void	stack_move_printer(t_int_list *stack)
{
	t_int_list	*aux;

	ft_printf("[i]	||	(val)	||	(ra)	(rra)	(rb)	(rrb)	(rr)	(rrr)	||	(opt.)	(total)\n");
	aux = stack;
	ft_printf("[%d]	||	(%d)	||	(%d)	(%d)	(%d)	(%d)	(%d)	(%d)	||	(%d)	(%d)\n",aux->index, aux->val, aux->ra, aux->rra, aux->rb, aux->rrb, aux->rr, aux->rrr, aux->option, aux->total);
	if (aux->next)
	{
		aux = aux->next;
		while (aux->index != 0)
		{
			ft_printf("[%d]	||	(%d)	||	(%d)	(%d)	(%d)	(%d)	(%d)	(%d)	||	(%d)	(%d)\n",aux->index, aux->val, aux->ra, aux->rra, aux->rb, aux->rrb, aux->rr, aux->rrr, aux->option, aux->total);
			aux = aux->next;
		}
	}
	ft_printf("\n");
}

void	stacks_move_printer(t_int_list *stack_a, t_int_list *stack_b)
{
	if (stack_a)
	{
		ft_printf("STACK A:\n");
		stack_move_printer(stack_a);
	}
	if (stack_b)
	{
		ft_printf("STACK B:\n");
		stack_move_printer(stack_b);
	}
}
