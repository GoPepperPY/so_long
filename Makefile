# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 11:22:06 by goda-sil          #+#    #+#              #
#    Updated: 2023/11/23 15:15:06 by goda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = sources/main.c sources/starter.c sources/map.c sources/math.c sources/get_next_line/get_next_line.c \
		sources/get_next_line/get_next_line_utils.c

MINILIBX = ./minilibx-linux/libmlx.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SRC_OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(SRC_OBJS) $(MINILIBX)
	@$(CC) $(CFLAGS) $(SRC_OBJS) $(MINILIBX) -lXext -lX11 -o $(NAME)

clean:
	@$(RM) $(SRC_OBJS)
	@$(MAKE) clean -C ./minilibx-linux

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) clean -C ./minilibx-linux

re: fclean all