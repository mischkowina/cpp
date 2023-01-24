/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:41:19 by smischni          #+#    #+#             */
/*   Updated: 2023/01/24 14:21:34 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << PINK "AMateria Default Constructor called." DEFAULT << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << PINK "AMateria Type Constructor called." DEFAULT << std::endl;
}

AMateria::AMateria(AMateria const &rhs)
{
	std::cout << PINK "AMateria Copy Constructor called." DEFAULT << std::endl;
	*this = rhs;
}

AMateria::~AMateria(void)
{
	std::cout << BLUE "AMateria Destructor called." DEFAULT << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	std::cout << PINK "AMateria Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs && this->type.compare(rhs.type))
		std::cout << "Assignment failed: different Materia types." << std::endl;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	if (this->type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
