# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 15:15:56 by akdovlet          #+#    #+#              #
#    Updated: 2025/07/04 17:11:42 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Violence

SRC_DIR		:= src
SRC			:=	HumanA.cpp	\
				HumanB.cpp	\
				main.cpp	\
				Weapon.cpp

BUILD		:= .build

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ			:= $(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(SRC))

DEP			:= $(OBJ:.o=.d)

CC			:= c++

CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98 -MMD -MP -Iinclude

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
