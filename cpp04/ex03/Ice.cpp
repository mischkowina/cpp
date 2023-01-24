/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:45:45 by smischni          #+#    #+#             */
/*   Updated: 2023/01/24 14:22:33 by smischni         ###   ########.fr       */
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
	if (this != &rhs && this->type.compare(rhs.type))
		std::cout << "Assignment failed: different Materia types." << std::endl;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	AMateria	*clone = new Ice();
	return (clone);
}

void	Ice::use(ICharacter &target)
{
	if (this->type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
