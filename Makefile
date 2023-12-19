# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 11:22:06 by goda-sil          #+#    #+#              #
#    Updated: 2023/12/06 14:54:48 by goda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = sources/main.c sources/starter.c sources/map.c sources/aux.c sources/checker.c sources/get_next_line.c sources/ft_bzero.c \
		sources/ft_strchr.c sources/ft_strjoin.c sources/ft_strlen.c sources/ft_strtrim.c sources/ft_calloc.c sources/printf_utils.c \
		sources/printf_utils_two.c sources/ft_printf.c sources/checker_2.c sources/action_moves.c

MINILIBX = ./minilibx-linux/libmlx.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SRC_OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(SRC_OBJS) $(MINILIBX)
	@$(CC) $(CFLAGS) $(SRC_OBJS) $(MINILIBX) -lXext -lX11 -o $(NAME)

c:
	@$(RM) $(SRC_OBJS)
	@$(MAKE) clean -C ./minilibx-linux

f: c
	@$(RM) $(NAME)
	@$(MAKE) clean -C ./minilibx-linux

r: f all