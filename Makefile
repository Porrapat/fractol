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
# CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		=	
CFLAGSMLX	=  -Lminilibx-linux -Iminilibx-linux -lmlx -lXext -lX11
CFLAGSMORE	=  -lm -lbsd

SRC_DIR		=	srcs
SRC			=	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
# $(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(SRC) -o $@ $(CFLAGSMLX) $(CFLAGSMORE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
