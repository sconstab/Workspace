# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 18:52:04 by sconstab          #+#    #+#              #
#    Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

PATH_LIBFT = ./libft/

PATH_SRC = ./srcs/

SRCS = ft_ls.c\

FLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(PATH_SRC), $(SRCS))

SRC_O = $(patsubst %.c, %.o, $(SRC))

all:			$(NAME)

$(NAME):		$(SRC_O)
	@make -C $(PATH_LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(PATH_LIBFT)libft.a
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(PATH_SRC)%.o:	$(PATH_SRC)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(PATH_LIBFT) clean
	@/bin/rm -rf $(SRC_O)
	@echo "\033[31mObject Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean:			clean
	@make -C $(PATH_LIBFT) fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re:				fclean all

.PHONY:			all fclean clean re