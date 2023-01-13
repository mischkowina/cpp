/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:38:49 by smischni          #+#    #+#             */
/*   Updated: 2023/01/13 17:27:04 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << PINK "Default constructor called." DEFAULT << std::endl;
	this->value = 0;
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << PINK "Copy constructor called." DEFAULT << std::endl;
	*this = src;
}

Fixed::Fixed(int const i)
{
	// std::cout << PINK "INT constructor called." DEFAULT << std::endl;
	this->value = i << this->fract_bits;
}

Fixed::Fixed(float const f)
{
	// std::cout << PINK "FLOAT constructor called." DEFAULT << std::endl;
	this->value = roundf(f * (1 << this->fract_bits));
}

Fixed::~Fixed(void)
{
	// std::cout << GREEN "Destructor called." DEFAULT << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	// std::cout << BLUE "Copy assignment operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	sum;
	
	sum.setRawBits(this->value + rhs.value);
	return (sum);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	diff;
	
	diff.setRawBits(this->value - rhs.value);
	return (diff);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	prod(this->toFloat() * rhs.toFloat());
	return (prod);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	div(this->toFloat() / rhs.toFloat());
	return (div);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->value < rhs.value);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->value <= rhs.value);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->value > rhs.value);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->value >= rhs.value);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->value == rhs.value);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->value != rhs.value);
}

Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);
	
	this->value++;
	return (copy);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);
	
	this->value--;
	return (copy);
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
