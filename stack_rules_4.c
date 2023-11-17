#include "push_swap.h"

void	ft_rra(t_int_list **stack_a, t_int_list **stack_b)
{
	(void)stack_b;
	ft_rev_r(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_int_list **stack_a, t_int_list **stack_b)
{
	(void)stack_a;
	ft_rev_r(stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_rev_r(stack_a);
	ft_rev_r(stack_b);
	ft_printf("rrr\n");
}

//------------------

void	ft_pa(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_p(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_pb(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_p(stack_a, stack_b);
	ft_printf("pb\n");
}
