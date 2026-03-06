# **************************************************************************** #
#                                CONFIG                                        #
# **************************************************************************** #

NAME        = bureaucrat	

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
INCLUDES    = -Iinclude

SRC_DIR     = src
OBJ_DIR     = obj

# **************************************************************************** #
#                                FILES                                         #
# **************************************************************************** #

SRC = \
	src/main.cpp \
	src/Bureaucrat.cpp \
	src/Form.cpp \

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                COLORS                                        #
# **************************************************************************** #

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RED     = \033[0;31m
RESET   = \033[0m

# **************************************************************************** #
#                                RULES                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re