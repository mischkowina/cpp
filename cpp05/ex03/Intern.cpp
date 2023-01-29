/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:57:26 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 17:46:47 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
	if (MESSAGE)
		std::cout << PINK "Intern Default Constructor called." DEFAULT << std::endl;
}

Intern::Intern(Intern const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "Intern Copy Constructor called." DEFAULT << std::endl;
	(void)rhs;
}

Intern::~Intern()
{
	if (MESSAGE)
		std::cout << BLUE "Intern Destructor called." DEFAULT << std::endl;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "Intern Copy Assignment Operator called." DEFAULT << std::endl;
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	AForm		*form = NULL;
	std::string	types[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int			i = 0;

	while (i < 3)
	{
		if (types[i] == name)
			break;
		i++;
	}

	switch (i)
	{
		case 0:
		{
			form = new RobotomyRequestForm(target);
			std::cout << "Intern created " << form->getName() << std::endl;
			break;
		}
		case 1:
		{
			form = new PresidentialPardonForm(target);
			std::cout << "Intern created " << form->getName() << std::endl;
			break;
		}
		case 2:
		{
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern created " << form->getName() << std::endl;
			break;
		}
		default:
		{
			std::cout << "Intern could not create form because of invalid form name: " << name << std::endl;
		}
	}
	return (form);
}
