#include "push_swap.h"

void	ft_s(t_int_list **stack)
{
	int		val;
	
	val = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = val;
}

//------------------

void	ft_r(t_int_list **stack)
{
	t_int_list	*aux;
	int		val;
	
	if (!(*stack)->next)
		return ;
	else
	{
		val = (*stack)->val;
		aux = (*stack)->next;
		while (aux != (*stack))
		{
			aux->prev->val = aux->val;
			aux = aux->next;
		}
		ft_stack_back(stack)->val = val;
	}
}

//------------------

void	ft_rev_r(t_int_list **stack)
{
	t_int_list	*aux;
	int		val;
	
	if (!(*stack)->next)
		return ;
	else
	{
		val = ft_stack_back(stack)->val;
		aux = ft_stack_back(stack);
		while (aux != (*stack))
		{
			aux->val = aux->prev->val;
			aux = aux->prev;
		}
		(*stack)->val = val;
	}
}
//------------------

void	ft_p_aux(t_int_list **start, t_int_list **finish)
{
	t_int_list	*moved;
	t_int_list	*aux;

	moved = (*start);
	ft_stack_back(start)->next = (*start)->next;
	(*start) = (*start)->next;
	(*start)->index--;
	if ((*start)->next)
	{
		aux = (*start)->next;
		while (aux->index != 0)
		{
			aux->index--;
			aux = aux->next;
		}
	}
	ft_stack_add_front(finish, moved);
	(*start)->prev = ft_stack_back(start);
	if ((*start)->prev == (*start) || (*start)->next == (*start))
	{
		(*start)->prev = NULL;
		(*start)->next = NULL;
	}
}

void	ft_p(t_int_list **start, t_int_list **finish)
{
	t_int_list	*moved;

	if (!(*start))
		return ;
	if (!(*start)->next)
	{
		moved = (*start);
		ft_stack_add_front(finish, moved);
		(*start) = NULL;
	}
	else
		ft_p_aux(start, finish);
}
