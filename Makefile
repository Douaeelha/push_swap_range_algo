# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 21:33:05 by delhajou          #+#    #+#              #
#    Updated: 2025/04/18 11:55:33 by delhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/algo.c\
srcs/error_freeing.c\
		srcs/main.c\
		srcs/stacks.c\
		srcs/operations.c\
		srcs/parsing.c\
		srcs/helpers.c\
		srcs/utils.c\
		srcs/additional.c\

OBJCS = $(SRCS:%.c=%.o)
CC = cc

CFLAGS = -Wall -Wextra -Werror 

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJCS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJCS)

$(LIBFT) :
	@make -C ./libft
%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -rf $(OBJCS)
	@make -C libft clean
fclean : clean 
	rm -rf $(NAME)
	@make -C libft fclean
re : clean fclean all 

.PHONY : clean 


