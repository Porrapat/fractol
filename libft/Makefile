# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                               +#+#+#+#+#+     +#+            #
#    Created: 2022/02/07 13:18:59 by porrapat          #+#    #+#              #
#    Updated: 2022/02/15 11:13:35 by ppetchda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memmove.c 			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strlen.c				\
		ft_isalpha.c 			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strncmp.c			\
		ft_strlcpy.c			\
		ft_strlcat.c			\
		ft_strnstr.c			\
		ft_atoi.c				\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_substr.c				\
		ft_strjoin.c 			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_strmapi.c			\
		ft_striteri.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		get_next_line.c			\
		get_next_line_utils.c	\
		ft_lstnew.c				\
		ft_lstadd_front.c		\
		ft_lstsize.c			\
		ft_lstlast.c			\
		ft_lstadd_back.c		\
		ft_lstclear.c			\
		ft_lstdelone.c			\
		ft_lstiter.c			\
		ft_lstmap.c				\

NAME = libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS = -c -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	-@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
