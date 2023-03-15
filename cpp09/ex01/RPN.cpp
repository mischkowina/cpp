/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:48 by smischni          #+#    #+#             */
/*   Updated: 2023/03/15 15:12:22 by smischni         ###   ########.fr       */
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

	if (input.empty())
		throw std::logic_error("Empty input.");

	while (!input.empty())
	{
		pos = input.find(' ', 0);
		element = input.substr(0, pos);
		if (!(this->isValidInt(element)) && !(this->isOperator(element)))
			throw std::logic_error("Invalid element: " + element);
		this->addToCalculation(element);
		if (pos != std::string::npos)
			input.erase(0, pos + 1);
		else
			input.clear();
	}
	if (_calculation.size() > 1)
		throw std::logic_error("Invalid / incomplete expression.");
		
}

RPN::~RPN() {}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		this->_calculation = rhs._calculation;
	return (*this);
}

int	RPN::getResult() const
{
	return _calculation.top();
}

void	RPN::addToCalculation(std::string element)
{
	if (isValidInt(element))
		_calculation.push(atoi(element.c_str()));
	else if (isOperator(element))
	{
		if (_calculation.empty())
			throw std::logic_error("Operand missing for " + element + " operator.");
		int	operand2 = _calculation.top();
		_calculation.pop();

		if (_calculation.empty())
			throw std::logic_error("Operand missing for " + element + " operator.");
		int	operand1 = _calculation.top();
		_calculation.pop();

		if (element == "+")
			_calculation.push(operand1 + operand2);
		else if (element == "-")
			_calculation.push(operand1 - operand2);
		else if (element == "*")
			_calculation.push(operand1 * operand2);
		else if (element == "/")
			_calculation.push(operand1 / operand2);
	}
}

bool	RPN::isValidInt(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '-' && i < (str.length() - 1))
			continue;
		else if (!isdigit(str[i]))
			return false;
	}
	
	int	nbr = atoi(str.c_str());
	if (nbr > 9 || nbr < -9)
		return false;
	
	return true;
}

bool	RPN::isOperator(std::string str)
{
	if (str.length() > 1)
		return false;

	if (str.find_first_of("+-*/", 0) == std::string::npos)
		return false;

	return true;
}
