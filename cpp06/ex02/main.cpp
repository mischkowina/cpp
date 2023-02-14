/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:32:54 by smischni          #+#    #+#             */
/*   Updated: 2023/02/14 18:24:18 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>

Base	*generate()
{
	time_t	timer;
	Base	*p;

	timer = time(NULL);
	if (timer % 3 == 0)
	{
		p = new A;
		std::cout << PINK "Base *p object of type A has been created." DEFAULT << std::endl;
	}
	else if (timer % 3 == 1)
	{
		p = new B;
		std::cout << PINK "Base *p object of type B has been created." DEFAULT << std::endl;
	}
	else
	{
		p = new C;
		std::cout << PINK "Base *p object of type C has been created." DEFAULT << std::endl;
	}
	return (p);
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "Base *p object is of type A." << std::endl;
	else if (b)
		std::cout << "Base *p object is of type B." << std::endl;
	else if (c)
		std::cout << "Base *p object is of type C." << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		std::cout << "Base &p object is of type A." << std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		std::cout << "Base &p object is of type B." << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		std::cout << "Base &p object is of type C." << std::endl;
		(void)c;
	}
	catch(const std::exception& e) {}
}

int	main(void)
{
	std::cout << std::endl;
	std::cout << YELLOW "***** Call generate()-function to create a random object *****" DEFAULT << std::endl;
	Base *p = generate();
	std::cout << YELLOW "***** Identify object type by handing over pointer to identify() *****" DEFAULT << std::endl;
	identify(p);
	std::cout << YELLOW "***** Identify object type by handing over reference to identify() *****" DEFAULT << std::endl;
	identify(*p);
	std::cout << std::endl;

	delete p;
}
