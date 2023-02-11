/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:44 by smischni          #+#    #+#             */
/*   Updated: 2023/02/11 19:55:23 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() 
{
	if (MESSAGE)
		std::cout << PINK "Span Default Constructor called." DEFAULT << std::endl;
}

Span::Span(unsigned int N) : maximum(N), isSorted(false)
{
	if (MESSAGE)
		std::cout << PINK "Span Parametric Constructor called." DEFAULT << std::endl;
}

Span::Span(Span const &rhs) : maximum(rhs.maximum), nbrs(rhs.nbrs), isSorted(rhs.isSorted)
{
	if (MESSAGE)
		std::cout << PINK "Span Copy Constructor called." DEFAULT << std::endl;
}

Span::~Span()
{
	if (MESSAGE)
		std::cout << BLUE "Span Destructor called." DEFAULT << std::endl;
}

Span	&Span::operator=(Span const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "Span Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
	{
		this->maximum = rhs.maximum;
		this->nbrs = rhs.nbrs;
		this->isSorted = rhs.isSorted;
	}
	return (*this);
}

void	Span::addNumber(int i)
{
	if (nbrs.size() < maximum)
	{
		nbrs.push_back(i);
		isSorted = false;
	}
	else
		throw NotEnoughSpace();
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	while (start < end)
	{
		addNumber(*start);
		start++;
	}
}

void	Span::fillRandom()
{
	if (nbrs.size() >= maximum)
		throw NotEnoughSpace();
	srand(time(NULL));	
	while (nbrs.size() < maximum)
		nbrs.push_back(rand() % 100000);
}

int	Span::shortestSpan()
{
	if (nbrs.size() < 2)
		throw NotEnoughNumbers();
	if (isSorted == false)
	{
		std::sort(nbrs.begin(), nbrs.end());
		isSorted = true;
	}
	std::vector<int>	copy(nbrs);
	std::adjacent_difference(nbrs.begin(), nbrs.end(), copy.begin());
	return(*(std::min_element(copy.begin(), copy.end())));
}

int	Span::longestSpan()
{
	if (nbrs.size() < 2)
		throw NotEnoughNumbers();
	if (isSorted == false)
	{
		std::sort(nbrs.begin(), nbrs.end());
		isSorted = true;
	}
	return(nbrs.back() - nbrs.front());
}

void	Span::printSpan() const
{
	std::vector<const int>::iterator i;
	i = nbrs.begin();
	while (i < nbrs.end())
	{
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;
}

const char	*Span::NotEnoughNumbers::what() const throw()
{
	return ("Minimum two values needed to calculcate span.");
}

const char	*Span::NotEnoughSpace::what() const throw()
{
	return ("There is not enough space to store all the input.");
}
