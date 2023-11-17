#include "push_swap.h"

void	ft_ra(t_int_list **stack_a, t_int_list **stack_b)
{
	(void)stack_b;
	ft_r(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_int_list **stack_a, t_int_list **stack_b)
{
	(void)stack_a;
	ft_r(stack_b);
	ft_printf("rb\n");
}

void	ft_rr(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	ft_printf("rr\n");
}
