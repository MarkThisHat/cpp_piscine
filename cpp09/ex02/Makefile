# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 19:37:25 by maalexan          #+#    #+#              #
#    Updated: 2024/10/30 15:59:21 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		:=	PmergeMe

# Directories for source, object and libraries
SRC_DIR		:=	./
OBJ_DIR		:=	./objs
HDR_DIR		:=	./

# Compilation flags
CC			:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I $(HDR_DIR)
DEBUG_FLAGS := -g -DDEBUG=1

# Source files
SRC			:=	main.cpp \
						PmergeMe.cpp


# Object files
OBJ			:=	$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(if $(DEBUG), $(DEBUG_FLAGS)) -c $< -o $@

debug: DEBUG = 1
debug: all

val: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}  || echo ""

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo Program $(NAME) isn\'t compiled

re: fclean all

.PHONY: all clean fclean re val
