# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsebille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:40:36 by hsebille          #+#    #+#              #
#    Updated: 2023/02/02 17:38:55 by hsebille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

MLX_FLAG = -L minilibx-linux -lmlx -lX11 -lXext -lm -lz

NAME = so_long

SRCS = so_long.c get_next_line.c map_drawing.c can_move.c utils.c \
	   close_game.c map_reading.c gameplay.c utils2.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	make -C minilibx-linux
	make -C ./ft_printf
	$(CC) $(CFLAGS) -g -L libft -I libft -L ft_printf -I ft_printf $(OBJS) -l:libft.a -l:libftprintf.a -o $(NAME) $(MLX_FLAG)
	
all: $(NAME)

clean:
	/bin/rm -f $(OBJS)
	$(MAKE) -C ./libft clean
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C ./ft_printf clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean
	make -C ./ft_printf fclean

re: fclean all
