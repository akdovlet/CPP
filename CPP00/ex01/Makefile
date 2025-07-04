# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 18:07:01 by akdovlet          #+#    #+#              #
#    Updated: 2025/07/01 17:18:09 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= PhoneBook

SRC_DIR		:= src
SRC			:=	main.cpp		\
				PhoneBook.cpp	\
				Contact.cpp

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
