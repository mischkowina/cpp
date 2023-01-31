/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:47:50 by smischni          #+#    #+#             */
/*   Updated: 2023/01/31 17:52:58 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <exception>

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define BLUE "\033[36m"
# define YELLOW "\033[33m"

# define CHAR_CONV 0
# define INT_CONV 1
# define FLOAT_CONV 2
# define DOUBL_CONV 3

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &rhs);
		~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter const &rhs);
	
	public:
		static void	convert(std::string str);

		class InvalidInputException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

#endif
