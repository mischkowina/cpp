/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:15 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 16:53:59 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		std::cout << YELLOW "******** Case 1: Bureaucrat grade 1, can sign and execute anything ********" DEFAULT << std::endl;
		AForm *f1 = new PresidentialPardonForm("Joe");
		AForm *f2 = new RobotomyRequestForm("Chandler");
		AForm *f3 = new ShrubberyCreationForm("home");
		Bureaucrat	b("Bill", 1);
		
		b.signForm(*f1);
		b.executeForm(*f1);
		b.signForm(*f2);
		b.executeForm(*f2);
		b.signForm(*f3);
		b.executeForm(*f3);

		delete f1;
		delete f2;
		delete f3;
	}
	{
		std::cout << YELLOW "******** Case 2: Bureaucrat grade 50, can sign ShrubberyCreationForm and RobotomyRequestForm, but only excute ShrubberyCreationForm ********" DEFAULT << std::endl;
		AForm *f1 = new PresidentialPardonForm("Joe");
		AForm *f2 = new RobotomyRequestForm("Chandler");
		AForm *f3 = new ShrubberyCreationForm("home2");
		Bureaucrat	b("Doug", 50);
		
		b.signForm(*f1);
		b.executeForm(*f1);
		b.signForm(*f2);
		b.executeForm(*f2);
		b.signForm(*f3);
		b.executeForm(*f3);

		delete f1;
		delete f2;
		delete f3;
	}
	{
		std::cout << YELLOW "******** Case 3: Bureaucrat grade 150, can't do shit ********" DEFAULT << std::endl;
		AForm *f1 = new PresidentialPardonForm("Joe");
		AForm *f2 = new RobotomyRequestForm("Chandler");
		AForm *f3 = new ShrubberyCreationForm("home2");
		Bureaucrat	b("Jeff", 150);
		
		b.signForm(*f1);
		b.executeForm(*f1);
		b.signForm(*f2);
		b.executeForm(*f2);
		b.signForm(*f3);
		b.executeForm(*f3);

		delete f1;
		delete f2;
		delete f3;
	}
	return (0);
}
