# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 14:34:01 by sconstab          #+#    #+#              #
#    Updated: 2020/05/31 14:34:01 by sconstab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN	= ./bin/

all:
	mkdir -p $(BIN)
	make -C checker.c
	cp ./checker.o $(BIN)
	make -C push_swap.c
	cp ./push_swap.o $(BIN)

clean:
	rm -rf $(BIN)
	make -C checker.o clean
	make -C push_swap.o clean

fclean:
	rm -rf $(BIN)
	make -C checker.o fclean
	make -C push_swap.o fclean

re: fclean all