# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 14:02:38 by akolvakh          #+#    #+#              #
#    Updated: 2019/04/27 11:48:03 by akolvakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 

CC = clang

FLAGS = -Wall -Werror -Wextra -I $(H) -o $(NAME)
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(H_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./libmlx/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)includes/

H_LIST = fractol.h
H_DIR = ./includes/
H = $(addprefix $(H_DIR), $(H_LIST))

SRC_DIR = ./sources/
SRC_LIST = main.c\
set_julia.c\
set_carpet.c\
set_ship.c\
set_mandel.c\
set_tricorn.c\
controls.c\
initialization.c\
manipulation.c\
system.c\
pipeline.c\
core.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "\n$(NAME): object files were created"
	@echo "$(NAME): $(NAME) was created"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(OBJ_DIR) was created"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(H)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo ".\c"

$(LIBFT):
	@echo "$(NAME): Creating $(LIBFT)..."
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): Creating $(MINILIBX)..."
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(OBJ_DIR) was deleted"
	@echo "$(NAME): object files were deleted"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(MINILIBX) was deleted"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(LIBFT) was deleted"
	@rm -f $(NAME)
	@echo "$(NAME): $(NAME) was deleted"

re:
	@$(MAKE) fclean
	@$(MAKE) all
