NAME		=	fdf

LIB			=	libftprintf/
LIB_N		=	libftprintf.a

SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
INC_DIR 	= ./includes/

SRC			=	main.c \
				read_map.c \
				mod_function.c \
				write_data_to_window.c \
				projection.c \
				control.c \
				resize.c \

LIBFT 		= $(LIBFT_DIR)libftprintf.a
LIBFT_DIR 	= ./libftprintf/
LIBFT_INC	= $(LIBFT_DIR)
MLXFLAGS	= -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC_FLAGS	= -O3 -Wall -Wextra -Werror
CC 			= gcc


all:$(NAME) 

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@printf "\033[1;32mfdf created \033[0m\n"

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@$(CC) -c  $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

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
