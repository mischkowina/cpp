# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 09:47:57 by smischni          #+#    #+#              #
#    Updated: 2022/11/29 10:01:40 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pendantic-errors

SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	$(MAKE) clean

grind:	all
	valrgind --leack-check=full ./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re
