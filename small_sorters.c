#include "push_swap.h"

void	two_sorter(t_int_list **stack, t_int_list **ignored)
{
	if ((*stack)->val > (*stack)->next->val)
		ft_sa(stack, ignored);
}

void    three_sorter(t_int_list **stack, t_int_list **ignored)
{
    if ((*stack)->next->val > (*stack)->val && (*stack)->next->val > (*stack)->next->next->val)
        ft_rra(stack, ignored);
    if ((*stack)->val > (*stack)->next->val && (*stack)->val > (*stack)->next->next->val)
        ft_ra(stack, ignored);
    if ((*stack)->val > (*stack)->next->val)
        ft_sa(stack, ignored);
}
