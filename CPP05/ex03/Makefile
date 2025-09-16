# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 15:15:56 by akdovlet          #+#    #+#              #
#    Updated: 2025/09/16 21:02:11 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= intern

SRC_DIR		:=	src
SRC			:=	main.cpp	\
				Bureaucrat.cpp	\
				AForm.cpp		\
				ShrubberyCreationForm.cpp	\
				RobotomyRequestForm.cpp		\
				PresidentialPardonForm.cpp

BUILD		:= .build

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ			:= $(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(SRC))

DEP			:= $(OBJ:.o=.d)

CXX := c++

CXXFLAGS	= -Wall -Werror -Wextra -Wshadow -std=c++98 -MMD -MP -Iinclude -g

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

debug: fclean debug_compile
	
debug_compile: CXXFLAGS+= -g -D DEBUG=1
debug_compile: all;

-include $(DEP)

.PHONY: all clean fclean re 
