/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:15 by smischni          #+#    #+#             */
/*   Updated: 2023/01/26 15:50:35 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << YELLOW "******** Case 1: Valid values, incrementing and decrementing possible (no exceptions) ********" DEFAULT << std::endl;
		try {
			Bureaucrat b1;
			Bureaucrat b2("Joe");
			Bureaucrat b3(70);
			Bureaucrat b4("Chandler", 31);
			Bureaucrat b5(b4);
			Bureaucrat b6;
			b6 = b2;
			std::cout << "b1: " << b1 << std::endl;
			std::cout << "b2: " << b2 << std::endl;
			std::cout << "b3: " << b3 << std::endl;
			std::cout << "b4: " << b4 << std::endl;
			std::cout << "b5: " << b5 << std::endl;
			std::cout << "b6: " << b6 << std::endl;
			b1.incrementGrade();
			b4.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << YELLOW "******** Case 2: Constructor(string), decrement grade 150 (exception for decrementing) ********" DEFAULT << std::endl;
		Bureaucrat b1("Joe");
		try {
			std::cout << b1 << std::endl;
			b1.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << YELLOW "******** Case 3: Constructor(int), increment grade 1 (exception for incrementing) ********" DEFAULT << std::endl;
		Bureaucrat b1(1);
		try {
			std::cout << b1 << std::endl;
			b1.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << YELLOW "******** Case 4: Constructor(string, int), invalid grade at initialisation (exception in constructor) ********" DEFAULT << std::endl;
		try {
			Bureaucrat b1("Ross", 356);
			std::cout << b1 << std::endl;
			b1.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}
