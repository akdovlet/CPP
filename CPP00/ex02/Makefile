# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 17:21:23 by akdovlet          #+#    #+#              #
#    Updated: 2025/09/02 19:39:29 by akdovlet         ###   ########.fr        #
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

CXX := c++

CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98 -MMD -MP -Iinclude

$(BUILD):
	@mkdir -p $(BUILD)

all:  $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BUILD)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re 
