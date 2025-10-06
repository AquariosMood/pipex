# Library name
LIB_NAME = lib/libft.a

# Compiler and options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_INC_DIR = lib/inc

# Source files for the main program
MAIN_SRC_FILES = $(SRC_DIR)/cmd.c $(SRC_DIR)/free_errors.c $(SRC_DIR)/main.c $(SRC_DIR)/utils.c
MAIN_OBJ_FILES = $(MAIN_SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Source files for the bonus
BONUS_SRC_FILES = $(SRC_DIR)/bonus.c $(SRC_DIR)/free_errors.c $(SRC_DIR)/utils.c $(SRC_DIR)/execute_pipe_bonus.c
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default rule
all: pipex

# Compilation rules for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_INC_DIR) -o $@ -c $<

# Compilation rule for the main program
pipex: $(MAIN_OBJ_FILES) $(LIB_NAME)
	$(CC) -o pipex $(MAIN_OBJ_FILES) -Llib -lft

# Clean rule for object files
clean:
	rm -rf $(OBJ_DIR)

# Full clean rule
fclean: clean
	rm -f pipex pipex_bonus

# Full rebuild rule
re: fclean all

# Compilation rule for the bonus
bonus: $(BONUS_OBJ_FILES) $(LIB_NAME)
	@$(CC) $(CFLAGS) -o pipex_bonus $(BONUS_OBJ_FILES) -Llib -lft

# Phony targets
.PHONY: all clean fclean re bonus
