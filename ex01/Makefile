# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 18:07:01 by akdovlet          #+#    #+#              #
#    Updated: 2025/06/26 20:27:02 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= PhoneBook

SRC			:=	main.cpp		\
				PhoneBook.cpp	\
				Contact.cpp
BUILD		:= .build
OBJ			:= $(SRC:.cpp=.o)
OBJ			:= $(addprefix $(BUILD)/, $(OBJ))
DEPS		:= $(OBJ:.o=.d)

CC			:= c++

CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

$(BUILD):
	@mkdir -p $(BUILD)

all: create_dir $(NAME)

create_dir: | $(BUILD)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BUILD)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
