/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:04 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 17:26:09 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << PINK "Dog Default Constructor called." DEFAULT << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const &src)
{
	std::cout << PINK "Dog Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << BLUE "Dog Destructor called." DEFAULT << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
		this->brain = rhs.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOOFF!" << std::endl;
}
