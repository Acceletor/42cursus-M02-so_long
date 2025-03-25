# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 15:23:19 by ksuebtha          #+#    #+#              #
#    Updated: 2025/03/25 15:23:20 by ksuebtha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Directories
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
INC = -I ./include/
OBJ_DIR = obj/

# Complier and Cflag
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# essential name files
SRCBASE = main map_components map_reader map_utils map_validator \
		frees game game_utils loader renders player update_position
SRC = $(addsuffix .c, $(addprefix sources/, $(SRCBASE))) \
		get_next_line/get_next_line.c  \
		get_next_line/get_next_line_utils.c 

SRCADD = $(SRCBASE) #add additional file

# Converts SRCS file paths from .c to .o and places them inside OBJ_DIR/
OBJ = $(SRC:sources/%.c=$(OBJ_DIR)%.o)

#MiniLibX
MLX_PATH = ./minilibx-linux 
MLX = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAG = -Lminilibx-linux -lmlx -lXext -lX11
# MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

start:
	@make all

# Ensure directories exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build Libraries
$(LIBFT):
	@make -C ./libft
$(PRINTF):
	@make -C ./printf
# Build Executable
all: $(NAME)
	@echo "\033[32m[Program is ready for use]\033[0m"

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) $(PRINTF)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAG) -o $(NAME)

# Rule to compile object files
$(OBJ_DIR)%.o: sources/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning Rules
clean: 
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./libft
	@make fclean -C ./printf

re: fclean all

.PHONY: start all clean fclean re
