/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:38:49 by smischni          #+#    #+#             */
/*   Updated: 2023/01/13 17:28:01 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	{
		std::cout << PINK "**** SUBJECT TESTS ****" DEFAULT << std::endl;
		
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		// std::cout << b << std::endl;
		// std::cout << Fixed::max( a, b ) << std::endl << std::endl;
	}
	{
		std::cout << std::endl << PINK "**** OWN TESTS ****" DEFAULT << std::endl << std::endl;
		Fixed a(3);
		Fixed b(1.5f);

		std::cout << "a = " << a << "; b = " << b << std::endl << std::endl;
		std::cout << "Arithmetic operators:" << std::endl;
		std::cout << "a + b = " << (a + b) << std::endl;
		std::cout << "a - b = " << (a - b) << std::endl;
		std::cout << "a * b = " << (a * b) << std::endl;
		std::cout << "a / b = " << (a / b) << std::endl;

		std::cout << std::endl << "Comparison operators (0 = false, 1 = true):" << std::endl;
		std::cout << "a < b : " << (a < b) << std::endl;
		std::cout << "a <= b : " << (a <= b) << std::endl;
		std::cout << "a > b : " << (a > b) << std::endl;
		std::cout << "a >= b : " << (a >= b) << std::endl;
		std::cout << "a == b : " << (a == b) << std::endl;
		std::cout << "a != b : " << (a != b) << std::endl;

		std::cout << std::endl << "Increment & decrement operators:" << std::endl;
		Fixed	c;
		std::cout << "c: " << c << std::endl;
		std::cout << "++c: " << ++c << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "c++: " << c++ << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "--c: " << --c << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "c--: " << c-- << std::endl;
		std::cout << "c: " << c << std::endl;

		std::cout << std::endl << "min() & max() member functions:" << std::endl;
		
	}
	return (0);
}
