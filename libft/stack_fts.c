#include "libft.h"

void	move_initializer(t_int_list **stack)
{
	t_int_list	*aux;
	int i;

	aux = (*stack);
	i = 0;
	while (i < ft_stack_size(stack))
	{
		aux->ra = -1;
		aux->rra = -1;
		aux->rb = -1;
		aux->rrb = -1;
		aux->rr = -1;
		aux->rrr = -1;
		aux->option = -1;
		aux->total = -1;
		i++;
		if (aux->next)
			aux = aux->next;
	}
}

void	stacks_move_initializer(t_int_list **stack_a, t_int_list **stack_b)
{
	move_initializer(stack_a);
	move_initializer(stack_b);
}

t_int_list	*ft_stack_new(long val)
{
	t_int_list	*new;

	new = malloc(sizeof(t_int_list));
	if (!new)
		return (NULL);
	new->index = 0;
	new->val = val;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_stack_empty_add(t_int_list **stack, t_int_list *new)
{	
	*stack = new;
	new->index = 0;
	new->prev = NULL;
	new->next = NULL;
}

void	ft_stack_add_front(t_int_list **stack, t_int_list *new)
{
	t_int_list	*aux;

	if (!(*stack))
		ft_stack_empty_add(stack, new);
	else
	{
		new->index = 0;
		new->prev = ft_stack_back(stack);
		new->next = (*stack);
		ft_stack_back(stack)->next = new;
		(*stack)->prev = new;
		aux = *stack;
		while (aux != new)
		{
			aux->index++;
			aux = aux->next;
		}
		*stack = new;
	}
}

void	ft_stack_add_back(t_int_list **stack, t_int_list *new)
{
	if (!(*stack))
		ft_stack_empty_add(stack, new);
	else
	{
		new->prev = ft_stack_back(stack);
		new->next = (*stack);
		ft_stack_back(stack)->next = new;
		(*stack)->prev = new;
		new->index = new->prev->index + 1;
	}
}

int	ft_stack_size(t_int_list **stack)
{
	t_int_list	*aux;
	int	size;

	if (!(*stack))
		return (0);
	if (!(*stack)->next)
		return (1);
	aux = (*stack)->next;
	size = 1;
	while(aux->index != 0)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

t_int_list	*ft_stack_back(t_int_list **stack)
{
	t_int_list	*aux;

	if (!(*stack))
		return (NULL);
	if (!(*stack)->next)
		return (*stack);
	else
	{
		aux = (*stack)->next;
		while (aux->next->index != 0)
			aux = aux->next;
	}
	return (aux);
}

int	ft_stack_max_index(t_int_list *stack)
{
	t_int_list	*aux;
	t_int_list	*max_node;
	int	max;
	int	i;
	
	aux = stack;
	max = -2147483648;
	i = 0;
	while (i < ft_stack_size(&stack))
	{
		if (aux->val > max)
		{
			max_node = aux;
			max = aux->val;
		}
		aux = aux->next;
		i++;
	}
	return (max_node->index);
}

int	ft_stack_min_val(t_int_list *stack)
{
	t_int_list	*aux;
	int	min;
	int	i;
	
	aux = stack;
	min = 2147483647;
	i = 0;
	while (i < ft_stack_size(&stack))
	{
		if (aux->val < min)
			min = aux->val;
		aux = aux->next;
		i++;
	}
	return (min);
}

int	ft_stack_max_val(t_int_list *stack)
{
	t_int_list	*aux;
	int	max;
	int	i;
	
	aux = stack;
	max = -2147483648;
	i = 0;
	while (i < ft_stack_size(&stack))
	{
		if (aux->val > max)
			max = aux->val;
		aux = aux->next;
		i++;
	}
	return (max);
}
