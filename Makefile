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
CFLAGSMORE	=  -lm -lbsd -I$(INCLUDE) -lft -Llibft -Ilibft

SRC_DIR		=	srcs
SRC			=	$(SRC_DIR)/fractol.c		\
				$(SRC_DIR)/math.c			\
				$(SRC_DIR)/graphic.c		\
				$(SRC_DIR)/mandelbrot.c		\
				$(SRC_DIR)/julia.c			\
				$(SRC_DIR)/burning_ship.c	\
				$(SRC_DIR)/roberte.c		\
				$(SRC_DIR)/grid_system.c	\
				$(SRC_DIR)/color.c			\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
# $(MAKE) -C ./minilibx-linux
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC) -o $@ $(CFLAGSMLX) $(CFLAGSMORE)

clean:
	@$(MAKE) -C ./libft clean
	rm -f *.o

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f $(NAME)

norm:
	norminette srcs/math.c
	norminette srcs/fractol.c
	norminette srcs/graphic.c
	norminette srcs/grid_system.c
	norminette includes/fractol.h

re: fclean all

.PHONY: all clean fclean re
