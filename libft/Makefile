# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 14:53:50 by mjallada          #+#    #+#              #
#    Updated: 2022/04/04 14:56:07 by mjallada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME		:= libft.a
DIRS		:= libft

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
AR 			:= ar rc

INC_DIR		:= inc
SRC_DIR		:= src
BIN_DIR		:= bin

# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES	:= $(notdir $(basename $(wildcard $(SRC_DIR)/*.c)))
OBJ_FILES	:= $(addprefix $(BIN_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# **************************************************************************** #
# RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)$(NAME) compiled :)$(DEF_COLOR)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(BIN_DIR)
	@$(CC) -MD -c $(CFLAGS) -I $(INC_DIR) $< -o $@
	@echo "$(BLUE)Compiling $(notdir $<)$(END_COLOR)"

$(BIN_DIR):
	@mkdir $(BIN_DIR)
	@echo "Created $(BIN_DIR)/ directory in $(DIRS)/"

clean:
	@rm -rf $(BIN_DIR)
	@echo "$(YELLOW)$(NAME) object & dependency files cleaned.$(END_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) executable file cleaned.$(END_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME)!$(END_COLOR)"

-include $(OBJ_FILES:%.o=%.d)

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re
