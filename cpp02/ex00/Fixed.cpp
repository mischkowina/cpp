/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:38:49 by smischni          #+#    #+#             */
/*   Updated: 2023/01/12 11:10:54 by smischni         ###   ########.fr       */
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

Fixed::operator=(Fixed f)
{
	std::cout << BLUE "Copy assignment operator called." DEFAULT << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << GREEN "Destructor called." DEFAULT << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member function called." DEFAULT << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << YELLOW "setRawBits member function called." DEFAULT << std::endl;
}
