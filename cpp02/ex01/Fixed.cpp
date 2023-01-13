/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:38:49 by smischni          #+#    #+#             */
/*   Updated: 2023/01/13 15:55:58 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << PINK "Default constructor called." DEFAULT << std::endl;
	this->value = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << PINK "Copy constructor called." DEFAULT << std::endl;
	*this = src;
}

Fixed::Fixed(int const i)
{
	std::cout << PINK "INT constructor called." DEFAULT << std::endl;
	this->value = i << this->fract_bits;
}

Fixed::Fixed(float const f)
{
	std::cout << PINK "FLOAT constructor called." DEFAULT << std::endl;
	this->value = roundf(f * (1 << this->fract_bits));
}

Fixed::~Fixed(void)
{
	std::cout << GREEN "Destructor called." DEFAULT << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << BLUE "Copy assignment operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << YELLOW "getRawBits member function called." DEFAULT << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << YELLOW "setRawBits member function called." DEFAULT << std::endl;
	this->value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->value >> fract_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << fract_bits));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
