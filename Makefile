#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/03 05:02:18 by ppetchda          #+#    #+#              #
#    Updated: 2017/09/13 00:08:24 by ppetchda         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fractol
CC			=	gcc
CFLAGS		=	-Ofast 
CFLAGSMLX	=  -Lminilibx-linux -Iminilibx-linux -Imlx -lmlx -lXext -lX11 -lm -lbsd 

SRC_DIR		=	srcs
SRC			=	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(CFLAGSMLX) -o $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $@ $(CFLAGSMLX)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
