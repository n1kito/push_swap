# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 12:56:22 by mjallada          #+#    #+#              #
#    Updated: 2022/02/01 12:56:24 by mjallada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# son makefile a lui est clair : https://github.com/ccorsin/push_swap-42/blob/master/Makefile
# **************************************************************************** #
# VARIABLES

NAME 		= push_swap
INCLUDE 	= include/
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm
SRC_DIR 	= src/
OBJ_DIR 	= obj/

# **************************************************************************** #
# COLORS

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# **************************************************************************** #
# SOURCES

SRC_FILES = operation_push \
			operation_rotate \
			operation_swap \
			argument_checker \
			argument_parsing \
			cost_management \
			free_functions \
			main \
			push_swap_utils \
			sort_average_lists \
			sort_gps \
			sort_small_lists \
			sorting_utils \
			sort_long_lists \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# **************************************************************************** #

OBJF		= .cache_exists

all:		$(NAME)

$(NAME): 	$(OBJ)
			make -C libft
			@$(CC) -g -o $(NAME) $(OBJ) -L./libft -lft #retirer le -g que j'utilise pour debugger
			@echo "$(GREEN)$(NAME) compiled :)$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -g $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned.$(DEF_COLOR)"
			@make clean -C libft

fclean: clean
			@$(RM) -f $(NAME)
			@echo "$(BLUE)$(NAME) executable file cleaned.$(DEF_COLOR)"
			@$(RM) -f libft/libft.a
			@echo "$(BLUE)libft executable file cleaned as well!$(DEF_COLOR)"

re: 	fclean all
			@echo "$(GREEN)Cleaned all and rebuilt $(NAME) :)$(DEF_COLOR)"

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re