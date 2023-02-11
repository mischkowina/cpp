/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:08:06 by smischni          #+#    #+#             */
/*   Updated: 2023/02/11 19:56:36 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int	main()
{
	{
		std::cout << std::endl << YELLOW << "*** Mass Test ***" << DEFAULT << std::endl;
		try
		{
			Span sp = Span(20000);
			sp.fillRandom();
			// sp.printSpan();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			sp.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << YELLOW << "*** Example Subject Sheet ***" << DEFAULT << std::endl;
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << YELLOW << "*** Empty array ***" << DEFAULT << std::endl;
		try
		{
			Span sp = Span(0);
			sp.fillRandom();
			sp.printSpan();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			sp.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << YELLOW << "*** Copy constructor and copy assignment operator ***" << DEFAULT << std::endl;
		try
		{
			Span sp1 = Span(10);
			sp1.addNumber(11);
			std::cout << "sp1: ";
			sp1.printSpan();
			Span sp2 (sp1);
			sp2.addNumber(20);
			std::cout<< "sp2: ";
			sp2.printSpan();
			Span sp3 (0);
			sp3 = sp1;
			std::cout<< "sp3: ";
			sp3.printSpan();
			sp3.fillRandom();
			std::cout << "sp3: ";
			sp3.printSpan();
			std::cout << "sp1: ";
			sp1.printSpan();
			std::cout << sp1.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
