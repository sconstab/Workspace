# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 09:03:43 by sconstab          #+#    #+#              #
#    Updated: 2019/10/07 13:20:39 by sconstab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
FLAGS		=	-Wall -Werror -Wextra
CC			=	gcc
SRC			=	ft_atoi.c\
				ft_bzero.c\
				ft_find_replace.c\
				ft_intlen.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcnlen.c\
				ft_strcpy.c\
				ft_strcreturn.c\
				ft_strctrim.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strjoinfree.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strntrim.c\
				ft_strrchr.c\
				ft_strrev.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_wordcount.c\
				ft_get_next_line.c\
				lst_knock.c\
				lst_lstadd.c\
				lst_lstnew.c\
				lst_lstpush.c\
				lst_pop.c\
				lst_revrot.c\
				lst_rot.c\
				lst_swap.c\

INC 		=	-I ./includes/libft.h
SRC_DIR 	=	src
OBJ_DIR 	=	obj
OBJ			=	$(SRC:.c=.o)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: directory $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "\033[32m[Finished Compiling]\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INC)

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "\033[32m[Started Compiling]\033[0m"

clean: 
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "\033[31m[Object Files Removed]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME) Files Removed]\033[0m"

re: fclean all

.PHONY: clean all re fclean directory
