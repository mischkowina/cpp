/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:48 by smischni          #+#    #+#             */
/*   Updated: 2023/03/15 13:12:29 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &rhs)
{
	if (this != &rhs)
		*this = rhs;
}

RPN::RPN(std::string input)
{
	size_t		pos;
	std::string	element;

	while (!input.empty())
	{
		pos = input.find(' ', 0);
		element = input.substr(0, pos);
		//check element and add it to stack --> function making the checks + function calculating
		if (pos != std::string::npos)
			input.erase(0, pos + 1);
		else
			input.clear();
	}
}

RPN::~RPN() {}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		this->_result = rhs._result;
		this->_calculation = rhs._calculation;
	}
	return (*this);
}

int	RPN::getResult() const
{
	return _result;
}
