# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsebille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:40:36 by hsebille          #+#    #+#              #
#    Updated: 2023/01/25 16:48:00 by hsebille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

MLX_FLAG = -L minilibx-linux -lmlx -lX11 -lXext -lm -lz

NAME = so_long

SRCS = so_long.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) -g -L libft -I libft $(OBJS) -l:libft.a -o $(NAME) $(MLX_FLAG)
	
all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	/bin/rm -f $(OBJS)
	$(MAKE) -C ./libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
