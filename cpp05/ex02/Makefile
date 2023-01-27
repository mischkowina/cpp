# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 14:03:56 by smischni          #+#    #+#              #
#    Updated: 2023/01/27 15:11:58 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bureaucrat_02
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -Wunused

SRC		=	main.cpp \
			Bureaucrat.cpp \
			Form.cpp

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
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re leaks run message
