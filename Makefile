NAME = so_long
NAME_BONUS = so_long_bonus

# Directories
LIBFT = ./libft/libft.a
# PRINTF = ./printf/libftprintf.a
INC = -I ./include/
INC_BONUS = -I ./include_bonus/
OBJ_DIR = obj/
OBJ_BONUS_DIR = objbonus/

# Complier and Cflag
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# essential name files
SRCBASE = main
SRC = $(addsuffix .c, $(addprefix sources/, $(SRCBASE)))
SRCADD = $(SRCBASE) #add additional file
SRCBONUS = $(addsuffix _bonus.c, $(addprefix sources_bonus/, $(SRCADD)))

# Converts SRCS file paths from .c to .o and places them inside OBJ_DIR/
OBJ = $(SRC:sources/%.c=$(OBJ_DIR)%.o)
OBJ_BONUS = $(SRCBONUS:sources_bonus/%.c=$(OBJ_BONUS_DIR)%.o)

#MiniLibX
MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx_Linux.a
# MLX_FLAG = -Lmlx -lmlx -lXext -lX11
MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

# Ensure directories exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

# Build Libraries
$(LIBFT):
	@make -C ./libft

# Build Executable
all: $(NAME)


$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAG) -o $(NAME)

# Rule to compile object files
$(OBJ_DIR)%.o: sources/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Bonus Compilation
bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OBJ_BONUS_DIR) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAG) -o $(NAME_BONUS)

$(OBJ_BONUS_DIR)%.o: sources_bonus/%.c | $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning Rules
clean: 
	@$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft

re: fclean all

start:
	@make all

.PHONY: start all clean fclean re bonus
