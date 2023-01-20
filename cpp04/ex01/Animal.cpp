/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:59 by smischni          #+#    #+#             */
/*   Updated: 2023/01/20 18:47:01 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << PINK "Animal Default Constructor called." DEFAULT << std::endl;
	this->type = "Animal";
}

Animal::Animal(Animal const &src)
{
	std::cout << PINK "Animal Copy Constructor called." DEFAULT << std::endl;
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
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "*WEIRD ANIMAL NOISE*" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
