/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:33:21 by smischni          #+#    #+#             */
/*   Updated: 2023/01/25 20:31:29 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Jon Doe"), grade(150)
{
	if (MESSAGE)
		std::cout << "Bureaucrat Default Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{
	if (MESSAGE)
		std::cout << "Bureaucrat Constructor (string) called." << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name("Jon Doe")
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	if (MESSAGE)
		std::cout << "Bureaucrat Constructor (int) called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	if (MESSAGE)
		std::cout << "Bureaucrat Constructor (string, int) called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : name(rhs.name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	if (MESSAGE)
		std::cout << "Bureaucrat Constructor (string, int) called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	if (MESSAGE)
		std::cout << "Bureaucrat Destructor called." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->grade = rhs.grade;
	if (MESSAGE)
		std::cout << "Bureaucrat Copy Assignment operator called." << std::endl;
}

