/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:45:45 by smischni          #+#    #+#             */
/*   Updated: 2023/01/24 12:48:24 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	std::cout << PINK "Cure Default Constructor called." DEFAULT << std::endl;
	this->type = "cure";
}

Cure::Cure(Cure const &rhs)
{
	std::cout << PINK "Cure Copy Constructor called." DEFAULT << std::endl;
	*this = rhs;
}

Cure::~Cure(void)
{
	std::cout << BLUE "Cure Destructor called." DEFAULT << std::endl;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	std::cout << PINK "Cure Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	AMateria	*clone = new Cure();
	return (clone);
}

void	Cure::use(ICharacter &target)
{
	if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
