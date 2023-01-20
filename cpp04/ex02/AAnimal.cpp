/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:59 by smischni          #+#    #+#             */
/*   Updated: 2023/01/20 18:46:53 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << PINK "AAnimal Default Constructor called." DEFAULT << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << PINK "AAnimal Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << BLUE "AAnimal Destructor called." DEFAULT << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "*WEIRD ANIMAL NOISE*" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}
