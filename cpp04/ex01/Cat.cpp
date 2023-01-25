/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:04 by smischni          #+#    #+#             */
/*   Updated: 2023/01/25 17:56:31 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << PINK "Cat Default Constructor called." DEFAULT << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat const &src)
{
	std::cout << PINK "Cat Copy Constructor called." DEFAULT << std::endl;
	this->brain = new Brain;
	*(this->brain) = *(src.brain);
	this->type = src.type;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << BLUE "Cat Destructor called." DEFAULT << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	*(this->brain) = *(rhs.brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOOOOOOOOW" << std::endl;
}

void	Cat::setIdea(std::string newIdea, unsigned int index)
{
	this->brain->setIdea(newIdea, index);
}

std::string	Cat::getIdea(unsigned int index) const
{
	return (this->brain->getIdea(index));
}

Brain	&Cat::getBrain(void) const
{
	return (*this->brain);
}
