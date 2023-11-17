#include "push_swap.h"

int	out_of_bounds_test(char *text)
{
	char	*itoa_content;
	long		content;
	int		i;
	int		r;

	content = ft_atoi(text);
	itoa_content = ft_itoa(content);
	i = 0;
	r = 0;
	while (text[i] != '\0')
	{
		if (itoa_content[i] == text[i] && itoa_content[i] && text[i])
			i++;
		else
		{
			r = -1;
			break ;
		}
	}
	free(itoa_content);
	return (r);
}

/*int	out_of_bounds_test(char *text)
{
	char	*itoa_content;
	int		content;
	int		i;
	int		r;

	content = ft_atoi(text);
	itoa_content = ft_itoa(content);
	i = 0;
	r = 0;
	while (text[i] != '\0')
	{
		if (itoa_content[i] == text[i])
			i++;
		else
			r = -1;
	}
	free(itoa_content);
	return (r);
}*/

/*int	out_of_bounds_test(char *text)
{
	char	*itoa_content;
	int		content;
	int		i;

	content = ft_atoi(text);
	itoa_content = ft_itoa(content);
	i = 0;
	while (text[i] != '\0')
	{
		if (itoa_content[i] == text[i])
			i++;
		else
			return (-1);
	}
	return (0);
}*/

int	not_number_test(char *text)
{
	int	i;

	i = 0;
	if (text[0] == '-' || text[0] == '+')
		i++;
	while (text[i] != '\0')
	{
		if (text[i] >= '0' && text[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	repeated_number_test(int i, char **argv)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoi(argv[j]) != ft_atoi(argv[i]))
			j++;
		else
			return (-1);
	}
	return (0);
}

int	error_test(int argc, char **argv, t_int_list **stack_a)
{
	t_int_list	*new;
	int		n;

	n = 1;
	if (argc <= 1)
		return (-1);
	while (n < argc)
	{
		if (not_number_test(argv[n]) == -1)
			return (-1);
		if (out_of_bounds_test(argv[n]) == -1)
			return (-1);
		if (repeated_number_test(n, argv) == -1)
			return (-1);
		new = ft_stack_new(ft_atoi(argv[n]));
		new->index = n - 1;
		ft_stack_add_back(stack_a, new);
		n++;
	}
	return (0);
}
