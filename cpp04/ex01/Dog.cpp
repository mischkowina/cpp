/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:04 by smischni          #+#    #+#             */
/*   Updated: 2023/01/25 17:56:35 by smischni         ###   ########.fr       */
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
	this->brain = new Brain;
	*(this->brain) = *(src.brain);
	this->type = src.type;
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
	*(this->brain) = *(rhs.brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOOFF!" << std::endl;
}

void	Dog::setIdea(std::string newIdea, unsigned int index)
{
	this->brain->setIdea(newIdea, index);
}

std::string	Dog::getIdea(unsigned int index) const
{
	return (this->brain->getIdea(index));
}

Brain	&Dog::getBrain(void) const
{
	return (*this->brain);
}
