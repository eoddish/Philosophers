# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoddish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:40:26 by eoddish           #+#    #+#              #
#    Updated: 2021/07/22 16:41:25 by eoddish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= ft_routine.c ft_time.c ft_atoi.c ft_wait.c\
			  ft_clock.c main.c ft_init.c ft_isdigit.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c	
			$(CC) $(CFLAGS) -c $< -o $@

RM			= rm -f

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re

.SILENT:
