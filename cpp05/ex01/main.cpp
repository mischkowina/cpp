/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:15 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 14:24:28 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << YELLOW "******** Case 1: Valid grade values, Bureaucrat has high enough grade to sign f4, but not f3 (no exception, gets caught and handled in signForm()) ********" DEFAULT << std::endl;
		try {
			Form f1;
			Form f2("Stupid Form");
			Form f3(10, 60);
			Form f4("Greatest Form ever", 20, 90);
	
			std::cout << "f1: " << f1 << std::endl;
			std::cout << "f2: " << f2 << std::endl;
			std::cout << "f3: " << f3 << std::endl;
			std::cout << "f4: " << f4 << std::endl;
			
			Bureaucrat b1("Vinny", 15);
			b1.signForm(f4);
			std::cout << "f4: " << f4 << std::endl;
			b1.signForm(f3);
			std::cout << "f3: " << f3 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << YELLOW "******** Case 2: Grade too high/too low in Form constructor ********" DEFAULT << std::endl;
		try {
			Form f1(180, 1);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		try {
			Form f1(13, 180);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		try {
			Form f1(0, 1);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
			try {
			Form f1(80, -1);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}
