# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 22:40:36 by delhajou          #+#    #+#              #
#    Updated: 2024/11/24 20:33:45 by delhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_strjoin.c\
ft_striteri.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_atoi.c\

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJCS = $(SRCS:%.c=%.o)



all: $(NAME)

$(NAME): $(OBJCS)
	@ar rcs $@ $^

%.o : %.c libft.h 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJCS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
