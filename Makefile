# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolivier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 12:26:44 by nolivier          #+#    #+#              #
#    Updated: 2017/03/23 16:11:10 by nolivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nolivier.filler

SRC = ft_atoi.c \
	  ft_isdigit.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strchr.c \
	  ft_putchar.c \
	  ft_putnbr.c \
	  get_next_line.c \
	  filler.c \
	  ft_freegrid.c \
	  ft_play.c \
	  ft_print_pos.c \
	  ft_lstdel_posi.c \
	  ft_playable_posi.c \
	  ft_is_o.c \
	  ft_is_x.c \
	  ft_read_piece.c \
	  ft_read_plateau.c \
	  ft_read_size.c \
	  ft_calc_score_bis.c \
	  ft_freeintgrid.c \
	  ft_set_score.c \
	  ft_set_player.c

OUT = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^

$(NAME): $(OUT)
	gcc -o $(NAME) $(OUT) $(FLAG)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
