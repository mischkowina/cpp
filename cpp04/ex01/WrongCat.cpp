/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:57 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 15:37:03 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << PINK "WrongCat Default Constructor called." DEFAULT << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << PINK "WrongCat Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << BLUE "WrongCat Destructor called." DEFAULT << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WRONG MEEEEOW" << std::endl;
}
