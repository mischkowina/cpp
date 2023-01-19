/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:59 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 14:46:38 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << BLUE "Animal Default Constructor called." DEFAULT << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << BLUE "Animal Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << BLUE "Animal Destructor called." DEFAULT << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
}

void	Animal::makeSound(void)
{
	std::cout << "*WEIRD ANIMALIC NOISE" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
