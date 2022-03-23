# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:56:50 by mjallada          #+#    #+#              #
#    Updated: 2021/12/10 09:52:16 by mjallada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME		= libft.a
INCLUDE		= include
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= rm
AR 			= ar rc
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

SRC_FILES 	= ft_isdigit \
			ft_strlen \
			ft_strlcpy \
			ft_split \
			ft_putstr \
			ft_lstlast \

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# **************************************************************************** #

OBJF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)$(NAME) compiled :)$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned.$(DEF_COLOR)"

fclean: clean
			@$(RM) -f $(NAME)
			@echo "$(BLUE)$(NAME) executable file cleaned.$(DEF_COLOR)"

re: 	fclean all
			@echo "$(GREEN)Cleaned all and rebuilt $(NAME) :)$(DEF_COLOR)"

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re