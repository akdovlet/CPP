# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 18:07:01 by akdovlet          #+#    #+#              #
#    Updated: 2025/06/24 18:34:18 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= megaphone

SRC			:= megaphone.cpp

OBJ			:= $(SRC:.cpp=.o)

CC			:= c++

CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
