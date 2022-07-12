# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 02:56:24 by seongjch          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/06/23 07:37:33 by seongjch         ###   ########.fr        #
=======
#    Updated: 2022/06/23 02:58:55 by seongjch         ###   ########.fr        #
>>>>>>> b5745e2e0e297c0a427f145ebba9b4ecce3a908f
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

SRC = cmd_1.c ft_atoi.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
