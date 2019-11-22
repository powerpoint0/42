# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 21:16:54 by cjoaquin          #+#    #+#              #
#    Updated: 2019/10/24 22:50:28 by cjoaquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

GCC = gcc -Wall -Wextra -Werror 

HEADER = fillit.h

SRCS = .c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c $(HEADER)
	$(GCC) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJECT)
	$

