/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:33:21 by smischni          #+#    #+#             */
/*   Updated: 2023/01/26 17:14:10 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Jon Doe"), grade(150)
{
	if (MESSAGE)
		std::cout << PINK "Bureaucrat Default Constructor called." DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{
	if (MESSAGE)
		std::cout << PINK "Bureaucrat Constructor (string) called." DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name("Jon Doe")
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	if (MESSAGE)
		std::cout << PINK "Bureaucrat Constructor (int) called." DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	if (MESSAGE)
		std::cout << PINK "Bureaucrat Constructor (string, int) called." DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : name(rhs.name)
{
	this->grade = rhs.grade;
	if (MESSAGE)
		std::cout << PINK "Bureaucrat Copy Constructor called." DEFAULT << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	if (MESSAGE)
		std::cout << BLUE "Bureaucrat Destructor called." DEFAULT << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->grade = rhs.grade;
	if (MESSAGE)
		std::cout << PINK "Bureaucrat Copy Assignment operator called." DEFAULT << std::endl;
	return (*this);
}

std::string const	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if ((grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << this->name << "'s grade succesfully incremented." << std::endl;
	std::cout << "New grade: " << this->grade << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if ((grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << this->name << "'s grade succesfully decremented." << std::endl;
	std::cout << "New grade: " << this->grade << std::endl;
}

void	Bureaucrat::signForm(Form &form)
{
	if (!form.getIsSigned())
	{
		try {
			form.beSigned(*this);
			std::cout << this->name << " signed " << form.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << this->name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
		}
	}
	else
		std::cout << this->name << " could not sign " << form.getName() << " because it is already signed." << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Highest possible grade is 1.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException: Lowest possible grade is 150.");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
