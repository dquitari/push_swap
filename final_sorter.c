#include "push_swap.h"

int rb_fixer(int rb, int b_size)
{
    if (rb >= b_size)
        return (rb - b_size);
    else
        return (rb);
}

t_mm    mm_finder(t_int_list **stack)
{
    t_mm    mm;

    mm.min = ft_stack_min_val(*stack);
    mm.max = ft_stack_max_val(*stack);
    return (mm);
}

void    final_adjustment(t_int_list **stack_a, t_int_list **stack_b)
{
    int b_size;
    int final_rb;
    int final_rrb;

    b_size = ft_stack_size(stack_b);
    final_rb = ft_stack_max_index(*stack_b);
    final_rrb = b_size - final_rb;
    if (final_rb < final_rrb)
    {
        while (final_rb != 0)
        {
            ft_rb(stack_a, stack_b);
            final_rb--;
        }
    }
    else
    {
        while (final_rrb != 0)
        {
            ft_rrb(stack_a, stack_b);
            final_rrb--;
        }
    }
    while (*stack_b)
        ft_pa(stack_a, stack_b);
}

void    option_doer(t_int_list **stack_a, t_int_list **stack_b, t_int_list *best)
{
    if (best->option == 1)
    {
        while (best->ra > 0)
        {
            ft_ra(stack_a, stack_b);
            best->ra--;
        }
        while (best->rrb > 0)
        {
            ft_rrb(stack_a, stack_b);
            best->rrb--;
        }
    }
    if (best->option == 2)
    {
        while (best->rra > 0)
        {
            ft_rra(stack_a, stack_b);
            best->rra--;
        }
        while (best->rb > 0)
        {
            ft_rb(stack_a, stack_b);
            best->rb--;
        }
    }
    if (best->option == 3)
    {
        while (best->rr > 0)
        {
            ft_rr(stack_a, stack_b);
            best->rr--;
        }
        best->rb = best->rb - best->ra;
        while (best->rb > 0)
        {
            ft_rb(stack_a, stack_b);
            best->rb--;
        }
    }
    if (best->option == 4)
    {
        while (best->rr > 0)
        {
            ft_rr(stack_a, stack_b);
            best->rr--;
        }
        best->ra = best->ra - best->rb;
        while (best->ra > 0)
        {
            ft_ra(stack_a, stack_b);
            best->ra--;
        }
    }
    if (best->option == 5)
    {
        while (best->rrr > 0)
        {
            ft_rrr(stack_a, stack_b);
            best->rrr--;
        }
        best->rrb = best->rrb - best->rra;
        while (best->rrb > 0)
        {
            ft_rrb(stack_a, stack_b);
            best->rrb--;
        }
    }
    if (best->option == 6)
    {
        while (best->rrr > 0)
        {
            ft_rrr(stack_a, stack_b);
            best->rrr--;
        }
        best->rra = best->rra - best->rrb;
        while (best->rra > 0)
        {
            ft_rra(stack_a, stack_b);
            best->rra--;
        }
    }
}

t_int_list    *best_option_finder(t_int_list **stack_a, t_int_list **stack_b)
{
    t_int_list  *aux_a;
    t_int_list  *best;
    int total;
    int i;

    (void)stack_b;
    aux_a = (*stack_a);
    total = 2147483647;
    i = 0;
    while (i < ft_stack_size(stack_a))
    {
        if (aux_a->total < total)
        {
            total = aux_a->total;
            best = aux_a;

        }
        i++;
        aux_a = aux_a->next;
    }
    return (best);
}

void    opt_total_moves_filler(t_int_list **stack_a, t_int_list **stack_b)
{
    t_int_list  *aux_a;
    int i;

    (void)stack_b;
    aux_a = (*stack_a);
    i = 0;
    while (i < ft_stack_size(stack_a))
    {
        aux_a->total = 2147483647;
        if (aux_a->ra + aux_a->rrb < aux_a->total)
        {
            aux_a->total = aux_a->ra + aux_a->rrb;
            aux_a->option = 1;
        }
        if (aux_a->rra + aux_a->rb < aux_a->total)
        {
            aux_a->total = aux_a->rra + aux_a->rb;
            aux_a->option = 2;
        }
        if (aux_a->ra < aux_a->rb)
        {
            if(aux_a->rr + (aux_a->rb - aux_a->ra) < aux_a->total)
            {
                aux_a->total = aux_a->rr + (aux_a->rb - aux_a->ra);
                aux_a->option = 3;
            }
        }
        else if(aux_a->rr + (aux_a->ra - aux_a->rb) < aux_a->total)
        {
                aux_a->total = aux_a->rr + (aux_a->ra - aux_a->rb);
                aux_a->option = 4;
        }
        if (aux_a->rra < aux_a->rrb)
        {
            if(aux_a->rrr + (aux_a->rrb - aux_a->rra) < aux_a->total)
            {
                aux_a->total = aux_a->rrr + (aux_a->rrb - aux_a->rra);
                aux_a->option = 5;
            }
        }
        else if(aux_a->rrr + (aux_a->rra - aux_a->rrb) < aux_a->total)
        {
                aux_a->total = aux_a->rrr + (aux_a->rra - aux_a->rrb);
                aux_a->option = 6;
        }
        i++;
        aux_a = aux_a->next;
    }
}

void    rr_rrr_moves_filler(t_int_list **stack_a, t_int_list **stack_b)
{
    t_int_list  *aux_a;
    int i;

    (void)stack_b;
    aux_a = (*stack_a);
    i = 0;
    while (i < ft_stack_size(stack_a))
    {
        if (aux_a->ra < aux_a->rb)
            aux_a->rr = aux_a->ra;
        else
            aux_a->rr = aux_a->rb;
        if (aux_a->rra < aux_a->rrb)
            aux_a->rrr = aux_a->rra;
        else
            aux_a->rrr = aux_a->rrb;
        i++;
        aux_a = aux_a->next;
    }
}

void    rb_rrb_moves_filler(t_int_list **stack_a, t_int_list **stack_b)
{
    t_int_list  *aux_a;
    t_int_list  *aux_b;
    int i;
    int rb;
    t_mm   mm;

    aux_a = (*stack_a);
    i = 0;
    mm = mm_finder(stack_b);
    while (i < ft_stack_size(stack_a))
    {
        if (aux_a->val > mm.max || aux_a->val < mm.min)
            rb = ft_stack_max_index(*stack_b);
        else
        {
            aux_b = (*stack_b);
            rb = 0;
            while (rb < ft_stack_size(stack_b))
            {
                if (aux_a->val < aux_b->prev->val && aux_a->val > aux_b->val)
                    break ;
                else
                {
                    rb++;
                    aux_b = aux_b->next;
                }
            }
        }
        aux_a->rb = rb_fixer(rb, ft_stack_size(stack_b));
        aux_a->rrb = ft_stack_size(stack_b) - rb;
        i++;
        aux_a = aux_a->next;
    }
}

void    ra_rra_moves_filler(t_int_list **stack_a, t_int_list **stack_b)
{
    t_int_list  *aux_a;
    int i;

    (void)stack_b;
    aux_a = (*stack_a);
    i = 0;
    while (i < ft_stack_size(stack_a))
    {
        aux_a->ra = aux_a->index;
        aux_a->rra = ft_stack_size(stack_a) - aux_a->index;
        i++;
        aux_a = aux_a->next;
    }
}


void    final_sorter(t_int_list **stack_a, t_int_list **stack_b)
{
    ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
    while (*stack_a)
    {
        stacks_move_initializer(stack_a, stack_b);
        ra_rra_moves_filler(stack_a, stack_b);
        rb_rrb_moves_filler(stack_a, stack_b);
        rr_rrr_moves_filler(stack_a, stack_b);
        opt_total_moves_filler(stack_a, stack_b);
        //stacks_move_printer(*stack_a, *stack_b);
        option_doer(stack_a, stack_b, best_option_finder(stack_a, stack_b));
        /*while ((*stack_a)->rb > 0)
        {
            ft_rb(stack_a, stack_b);
            (*stack_a)->rb--;
        }*/
        ft_pb(stack_a, stack_b);
        //stacks_printer(*stack_a, *stack_b);
    }
    final_adjustment(stack_a, stack_b);
}
