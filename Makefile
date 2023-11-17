# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dquitari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 18:09:56 by dquitari          #+#    #+#              #
#    Updated: 2023/04/24 18:09:59 by dquitari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  aux_printers.c error_tests.c final_sorter.c push_swap.c small_sorters.c stack_rules.c stack_rules_2.c stack_rules_3.c stack_rules_4.c \

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g
SRCS_O		= $(SRCS:.c=.o)
RM		= rm -f
OBJS		= $(SRCS_O)
LIBFT		= libft

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)/*.o

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
