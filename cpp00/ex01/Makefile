# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 09:47:57 by smischni          #+#    #+#              #
#    Updated: 2023/01/07 18:19:28 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRC		=	main.cpp Phonebook.cpp Contact.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

leaks: all
	leaks --atExit -- ./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re leaks
