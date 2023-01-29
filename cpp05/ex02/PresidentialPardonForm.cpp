/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:55:21 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 15:57:5 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "John Doe")
{
	if (MESSAGE)
		std::cout << PINK "PresidentialPardonForm Default Constructor called." DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm(rhs)
{
	if (MESSAGE)
		std::cout << PINK "PresidentialPardonForm Copy Constructor called." DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
	if (MESSAGE)
		std::cout << PINK "PresidentialPardonForm Constructor (string) called." DEFAULT << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (MESSAGE)
		std::cout << BLUE "PresidentialPardonForm Destructor called." DEFAULT << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "PresidentialPardonForm Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

void	PresidentialPardonForm::execution() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
