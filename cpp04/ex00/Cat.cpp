/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:04 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 15:03:02 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << PINK "Cat Default Constructor called." DEFAULT << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &src)
{
	std::cout << PINK "Cat Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << BLUE "Cat Destructor called." DEFAULT << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOOOOOOOOW" << std::endl;
}
