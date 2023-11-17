/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:35:17 by dquitari          #+#    #+#             */
/*   Updated: 2023/09/11 09:35:19 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_list
{
	int		index;
	struct s_list	*prev;
	struct s_list	*next;
	long			val;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	int			rr;
	int			rrr;
	int			option;
	int			total;
	
}	t_int_list;

//base stack functions
void	moves_initializer(t_int_list **stack_a, t_int_list **stack_b);
t_int_list	*ft_stack_new(long val);
void	ft_stack_add_front(t_int_list **stack, t_int_list *new);
void	ft_stack_add_back(t_int_list **stack, t_int_list *new);
int			ft_stack_size(t_int_list **stack);
t_int_list	*ft_stack_back(t_int_list **stack);
int	ft_stack_max_index(t_int_list *stack);
int	ft_stack_min_val(t_int_list *stack);
int	ft_stack_max_val(t_int_list *stack);

char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
long			ft_atoi(const char *str);
int			ft_lstsize(t_int_list *lst);
int			ft_lstmax(t_int_list *lst);
int			ft_lstmin(t_int_list *lst);
int			ft_printf(const char *str, ...);
int			ft_abs(int n);
int			ft_print_char(char c);
int			ft_print_hex(unsigned int n, const char format);
int			ft_print_nbr(int n);
int			ft_print_ptr(unsigned long long ptr);
int			ft_print_str(char *str);
int			ft_print_unbr(unsigned int unbr);

#endif
