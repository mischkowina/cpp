# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 14:03:56 by smischni          #+#    #+#              #
#    Updated: 2023/01/20 17:58:01 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	polymorphism
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -Wunused

SRC		=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

run: all
	@./$(NAME)

leaks: all
	@leaks --atExit -- ./$(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re leaks run
