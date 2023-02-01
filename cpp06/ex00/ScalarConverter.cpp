/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:47:40 by smischni          #+#    #+#             */
/*   Updated: 2023/02/01 15:44:21 by smischni         ###   ########.fr       */
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
	int			mode = 4;
	char		c;
	int			i;
	float		f;
	double		d;
	int			precision = 1;
	std::string	c_str("");
	std::string	i_str("");
	
	if (str.length() < 1)
		throw ScalarConverter::InvalidInputException();
	if (str.length() == 1)
	{
		if (!isdigit(*(str.c_str())))//input is a single char
		{
			mode = CHAR_CONV;
			c = str.c_str()[0];
		}
		else//input is a single digit -> int
		{
			mode = INT_CONV;
			i = atoi(str.c_str());
		}
	}
	else
	{
		std::string edge[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
		int			idx = 0;
		while (idx < 6)
		{
			if (!str.compare(edge[idx]))
				break;
			idx++;
		}
		if (idx < 6)
		{
			c_str = "impossible";
			i_str = "impossible";
			if (idx < 3)//input is a float expression
			{
				mode = FLOAT_CONV;
				f = std::strtof(str.c_str(), NULL);
			}
			else//input is a double expression
			{
				mode = DOUBL_CONV;
				d = std::strtod(str.c_str(), NULL);
			}
		}
		else if (!str.compare("0.0"))//input is a double 0.0
		{
			mode = DOUBL_CONV;
			d = 0.0;
		}
		else if (!str.compare("0.0f"))//input is a float 0.0f
		{
			mode = FLOAT_CONV;
			f = 0.0f;
		}
		else
		{
			if (str.at(str.length() - 1) == 'f')//remove the last character if it is an f
			{
				mode = FLOAT_CONV;
				str.resize(str.length() - 1);
			}
			
			char	*endptr = NULL;
			double	tmp;
			tmp = std::strtod(str.c_str(), &endptr);//get number as double
			if (tmp == HUGE_VAL || tmp == -HUGE_VAL || errno == ERANGE)
				throw ScalarConverter::InvalidInputException();
			while (*endptr != '\0')
			{
				if (!isspace(*endptr))//throw inception in case there is invalid input after the number
					throw ScalarConverter::InvalidInputException();
				endptr++;
			}
			if (mode == FLOAT_CONV)//if it was float (ending with f), convert to float 
			{
				f = std::strtof(str.c_str(), NULL);
				if (f == HUGE_VALF || f == -HUGE_VALF)//if conversion impossible, invalid input
					throw ScalarConverter::InvalidInputException();
			}
			else if (str.find('.') == std::string::npos && tmp < INT_MAX && tmp > INT_MIN)//if input was int (no decimal point, within int range)
			{
				mode = INT_CONV;
				i = atoi(str.c_str());
			}
			else
			{
				mode = DOUBL_CONV;
				d = tmp;
			}
			if (str.find('.') != std::string::npos)
		precision = str.length() - (str.find_first_of('.') + 1);
		}
	}
	switch(mode)
	{
		case CHAR_CONV :
		{
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		}
		case INT_CONV:
		{
			if ((i < 31 && i >= 0) || i == 127)
				c_str = "Non displayable";
			else if (i > 127 || i < 0)
				c_str = "impossible";
			else
				c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		}	
		case FLOAT_CONV :
		{
			if ((f >= 0 && f < 31) || f == 127.0f)
				c_str = "Non displayable";
			else if (f > 127 || f < 0)
				c_str = "impossible";
			else
				c = static_cast<char>(f);
			if (f > INT_MAX || f < INT_MIN)
				i_str = "impossible";
			else
				i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		}
		case DOUBL_CONV :
		{
			if ((d >= 0 && d < 31) || d == 127.0f)
			{
				c_str = "Non displayable";
			}
			else if (d > 127 || d < 0)
				c_str = "impossible";
			else
				c = static_cast<char>(d);
			if (d > INT_MAX || d < INT_MIN)
				i_str = "impossible";
			else
				i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		}
	}
	if (c_str.empty() == false)
		std::cout << "char: " << c_str << std::endl;
	else
		std::cout << "char: \'" << c << "\'" << std::endl;
	if (i_str.empty() == false)
		std::cout << "int: " << i_str << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
}

const char	*ScalarConverter::InvalidInputException::what() const throw()
{
	return ("invalid or empty input.");
}
