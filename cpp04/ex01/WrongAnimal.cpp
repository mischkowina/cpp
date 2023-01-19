/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:57 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 15:36:15 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << PINK "WrongAnimal Default Constructor called." DEFAULT << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << PINK "WrongAnimal Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << BLUE "WrongAnimal Destructor called." DEFAULT << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*WEIRD AND WRONG ANIMALIC NOISE*" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
