# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chelmerd <chelmerd@student.wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 15:42:03 by chelmerd          #+#    #+#              #
#    Updated: 2021/11/23 10:34:11 by chelmerd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKE_FOLDER = ../
NAME = libft_tester
NAME_BONUS = libft_bonus_tester
HEADER = ../libft.h

all: m b

m: $(NAME).o makelib
	$(CC) -o $(NAME) $< -L ..

$(NAME).o: $(NAME).c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME_BONUS).o: $(NAME_BONUS).c
	$(CC) -c $(CFLAGS) -o $@ $<

makelib:
	make re -C $(MAKE_FOLDER)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: clean all