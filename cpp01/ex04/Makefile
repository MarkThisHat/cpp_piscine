# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:37:25 by maalexan          #+#    #+#              #
#    Updated: 2024/06/10 16:26:53 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		:=	sed_sob

# Directories for source, object and libraries
SRC_DIR		:=	./
OBJ_DIR		:=	./objs
HDR_DIR		:=	./

# Compilation flags
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -I $(HDR_DIR)

# Source files
SRC			:=	main.cpp \
#						Utils.cpp

# Object files
OBJ			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

val: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}  || echo ""

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo Program $(NAME) isn\'t compiled

re: fclean all

.PHONY: all clean fclean re val
