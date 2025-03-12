NAME = so_long
NAME_BONUS = so_long_bonus

# Directories
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
INC = -I ./include/
INC_BONUS = -I ./include_bonus/
OBJ_DIR = obj/
OBJ_BONUS_DIR = objbonus/

# Complier and Cflag
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# essential name files
SRCBASE = main map_components map_reader map_utils map_validator 
SRC = $(addsuffix .c, $(addprefix sources/, $(SRCBASE))) \
		get_next_line/get_next_line.c  \
		get_next_line/get_next_line_utils.c 

SRCADD = $(SRCBASE) #add additional file
SRCBONUS = $(addsuffix _bonus.c, $(addprefix sources_bonus/, $(SRCADD)))

# Converts SRCS file paths from .c to .o and places them inside OBJ_DIR/
OBJ = $(SRC:sources/%.c=$(OBJ_DIR)%.o)
OBJ_BONUS = $(SRCBONUS:sources_bonus/%.c=$(OBJ_BONUS_DIR)%.o)

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

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

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

# Bonus Compilation
bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OBJ_BONUS_DIR) $(OBJ_BONUS) $(PRINTF)
	@$(CC) $(CFLAGS) $(INC_BONUS) $(OBJ_BONUS) $(LIBFT) $(PRINTF) $(MLX_FLAG) -o $(NAME_BONUS)

$(OBJ_BONUS_DIR)%.o: sources_bonus/%.c | $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning Rules
clean: 
	@$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft
	@make fclean -C ./printf

re: fclean all


.PHONY: start all clean fclean re bonus
