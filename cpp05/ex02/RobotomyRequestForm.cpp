/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:51 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 15:43:35 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "John Doe")
{
	if (MESSAGE)
		std::cout << PINK "RobotomyRequestForm Default Constructor called." DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm(rhs)
{
	if (MESSAGE)
		std::cout << PINK "RobotomyRequestForm Copy Constructor called." DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
	if (MESSAGE)
		std::cout << PINK "RobotomyRequestForm Constructor (string) called." DEFAULT << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (MESSAGE)
		std::cout << BLUE "RobotomyRequestForm Destructor called." DEFAULT << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "RobotomyRequestForm Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

void	RobotomyRequestForm::execution() const
{
	std::cout << "* BBZZZZZZZZZZ BZZZZZ *" << std::endl;
	time_t	timer;
	timer = time(NULL);
	if (timer % 2 == 0)
		std::cout << this->getTarget() << " has been successfully robotomized." << std::endl;
	else
		std::cout << "Robotomy of " << this->getTarget() << " has failed." << std::endl;
}
