# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 14:03:56 by smischni          #+#    #+#              #
#    Updated: 2023/02/09 13:02:16 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	serialization
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -Wunused

SRC		=	main.cpp \
			Serializer.cpp \
			Data.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

run: all
	@./$(NAME)

message: $(SRC)
	$(CC) $(FLAGS) $(SRC) -D MESSAGE=1 -o $(NAME)
	@./$(NAME)

leaks: all
	@leaks --atExit -- ./$(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re leaks run message
