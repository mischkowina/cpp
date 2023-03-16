# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 14:03:56 by smischni          #+#    #+#              #
#    Updated: 2023/03/16 10:36:54 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -Wunused

SRC		=	main.cpp \
			PmergeMe.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
