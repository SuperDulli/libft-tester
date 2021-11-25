# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chelmerd <chelmerd@student.wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 15:42:03 by chelmerd          #+#    #+#              #
#    Updated: 2021/11/25 13:12:12 by chelmerd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MAKE_FOLDER = ../
NAME = libft_tester
NAME_BONUS = libft_bonus_tester
HEADER = ../libft.h
LIBFT_PATH = ../

all: m b

run: m
	./$(NAME)

run_bonus: b
	./$(NAME_BONUS)

m: $(NAME).o makelib
	$(CC) -o $(NAME) $< $(LIBFT_PATH)libft.a

b: $(NAME_BONUS).o makebonuslib
	$(CC) -o $(NAME_BONUS) $< $(LIBFT_PATH)libft.a

$(NAME).o: $(NAME).c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $< -I$(LIBFT_PATH)

$(NAME_BONUS).o: $(NAME_BONUS).c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $< -I$(LIBFT_PATH)

makelib:
	make re -C $(MAKE_FOLDER)

makebonuslib:
	make bonus -C $(MAKE_FOLDER)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: clean all