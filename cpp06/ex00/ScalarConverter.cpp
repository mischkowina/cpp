/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:47:40 by smischni          #+#    #+#             */
/*   Updated: 2023/01/31 18:03:58 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << PINK "ScalarConverter Default Constructor called." DEFAULT << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	std::cout << PINK "ScalarConverter Copy Constructor called." DEFAULT << std::endl;
	(void)rhs;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BLUE "ScalarConverter Destructor called." DEFAULT << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	std::cout << PINK "ScalarConverter Copy Assignment Operator called." DEFAULT << std::endl;
	(void)rhs;
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	int			mode;
	char		c;
	int			i;
	float		f;
	double		d;
	std::string	c_str("");
	std::string	i_str("");
	
	if (str.length() < 1)
		throw ScalarConverter::InvalidInputException();
	if (str.length() == 1 && !isdigit(*(str.c_str())))//input is a single char
	{
		mode = CHAR_CONV;
		c = str.c_str()[0];
		// i = static_cast<int>(c);
		// f = static_cast<float>(c);
		// d = static_cast<double>(c);
		// if (c < 33 || c == 127)
		// 	c_str = "Non displayable";
		// else
		// 	c_str = str;
		// std::cout << std::fixed << std::setprecision(1);
	}
	else
	{
		std::string edge[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
		int			i;
		while (i < 6)
		{
			if (!str.compare(edge[i++]))
				break;
		}
		if (i < 6)
		{
			c_str = "impossible";
			i_str = "impossible";
			if (i < 3)
			{
				mode = FLOAT_CONV;
				f = std::strtof(str);
			}
			else
			{
				mode = DOUBLE_CONV;
				f = std::strtod(str);
			}
			
		}
		else
		{
			//NUMBER CONVERSION!!!!! First double value, then check limits
		}
	}

	switch(mode)
	{
		case CHAR_CONV :
		{
			break ;
		}
		case INT_CONV:
		{
			break ;
		}	
		case FLOAT_CONV :
		{
			break;
		}
	}
	std::cout << "char: " << c_str << std::endl;
	std::cout << "int: " << i_str << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

const char	*ScalarConverter::InvalidInputException::what() const throw()
{
	return ("invalid or empty input.");
}
