# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 09:47:57 by smischni          #+#    #+#              #
#    Updated: 2023/01/10 16:13:03 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	losers
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic

SRC		=	main.cpp 
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
