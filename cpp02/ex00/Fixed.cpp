/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:38:49 by smischni          #+#    #+#             */
/*   Updated: 2023/01/12 13:13:34 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << PINK "Default constructor called." DEFAULT << std::endl;
}

Fixed::Fixed(Fixed f)
{
	std::cout << PINK "Copy constructor called." DEFAULT << std::endl;
}

Fixed	&Fixed::operator=(Fixed rhs)
{
	std::cout << BLUE "Copy assignment operator called." DEFAULT << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << GREEN "Destructor called." DEFAULT << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member function called." DEFAULT << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << YELLOW "setRawBits member function called." DEFAULT << std::endl;
	this->value = raw;
}
