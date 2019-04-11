# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 14:55:38 by ybuhai            #+#    #+#              #
#    Updated: 2019/04/11 12:14:57 by ybuhai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

LIB			=	libftprintf/
LIB_N		=	libftprintf.a

SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
INC_DIR 	= ./includes/

SRC			=	main.c \
				read_map.c \


LIBFT 		= $(LIBFT_DIR)libftprintf.a
LIBFT_DIR 	= ./libftprintf/
LIBFT_INC	= $(LIBFT_DIR)

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC_FLAGS	= -O3 
CC 			= gcc


all:$(NAME) 

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME) -lncurses
	@printf "\033[1;32mfdf created \033[0m\n"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	@$(CC) -c  $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS) $(DEBUG) 

$(LIBFT):
	@make -C $(LIBFT_DIR)


clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@printf "\033[1;33mobject deleted \033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@printf "\033[1;31mfdf deleted \033[0m\n"

re: fclean all

.PHONY: all clean fclean re
