# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 17:21:23 by akdovlet          #+#    #+#              #
#    Updated: 2025/07/03 16:24:30 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= tests

SRC_DIR		:= src
SRC			:=	tests.cpp		\
				Account.cpp

BUILD		:= .build

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ			:= $(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(SRC))

DEP			:= $(OBJ:.o=.d)

CC			:= c++

CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98 -MMD -MP -Iinclude -g

$(BUILD):
	@mkdir -p $(BUILD)

all: create_dir $(NAME)

create_dir: | $(BUILD)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BUILD)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re create_dir
