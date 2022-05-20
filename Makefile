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

INCLUDE		=	includes

CFLAGS		=	-Wall -Werror -Wextra
CFLAGSMLX	=  -Lminilibx-linux -Iminilibx-linux -lmlx -lXext -lX11
CFLAGSMORE	=  -lm -lbsd -I$(INCLUDE)

SRC_DIR		=	srcs
SRC			=	$(SRC_DIR)/fractol.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
# $(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(SRC) -o $@ $(CFLAGSMLX) $(CFLAGSMORE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

norm:
	norminette srcs/fractol.c
	norminette includes/fractol.h

re: fclean all

.PHONY: all clean fclean re
