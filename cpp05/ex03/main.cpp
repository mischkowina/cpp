/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:15 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 17:51:14 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		std::cout << YELLOW "******** SUBJECT TEST ********" DEFAULT << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << *rrf << std::endl;
		
		delete rrf;
	}
	{
		std::cout << std::endl;
		std::cout << YELLOW "******** OWN TEST ********" DEFAULT << std::endl;
		Intern	dude;
		AForm	*shrub;
		AForm	*pres;
		AForm	*robo;
		AForm	*test;

		shrub = dude.makeForm("shrubbery creation", "your garden");
		pres = dude.makeForm("presidential pardon", "Al Katzone");
		robo = dude.makeForm("robotomy request", "Saskia");
		test = dude.makeForm("stupid form", "Vinny");

		Bureaucrat b("Donald", 2);
		b.executeForm(*shrub);
		b.executeForm(*pres);
		b.executeForm(*robo);
		b.signForm(*pres);
		b.executeForm(*pres);

		delete shrub;
		delete pres;
		delete robo;
	}
	return (0);
}
