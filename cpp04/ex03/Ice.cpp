/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:45:45 by smischni          #+#    #+#             */
/*   Updated: 2023/01/22 16:56:21 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	std::cout << PINK "Ice Default Constructor called." DEFAULT << std::endl;
	this->type = "ice";
}

Ice::Ice(Ice const &rhs)
{
	std::cout << PINK "Ice Copy Constructor called." DEFAULT << std::endl;
	*this = rhs;
}

Ice::~Ice(void)
{
	std::cout << BLUE "Ice Destructor called." DEFAULT << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	std::cout << PINK "Ice Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	AMateria	*clone = new Ice();
	return (clone);
}
