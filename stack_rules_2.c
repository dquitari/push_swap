#include "push_swap.h"

void	ft_sa(t_int_list **stack_a, t_int_list **stack_b)
{
	(void)stack_b;
	ft_s(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_int_list **stack_a, t_int_list **stack_b)
{
	(void)stack_a;
	ft_s(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	ft_printf("ss\n");
}
