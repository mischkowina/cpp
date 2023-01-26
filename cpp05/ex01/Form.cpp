/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:47 by smischni          #+#    #+#             */
/*   Updated: 2023/01/26 19:07:47 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Standard Form"), isSigned(false), signGrade(150), execGrade(150)
{
	if (MESSAGE)
		std::cout << PINK "Form Default Constructor called." DEFAULT << std::endl;
}

Form::Form(std::string name) : name(name), isSigned(false), signGrade(150), execGrade(150)
{
	if (MESSAGE)
		std::cout << PINK "Form Constructor (string) called." DEFAULT << std::endl;
}

Form::Form(int signGrade, int execGrade) try: name("Standard Form"), isSigned(false), signGrade(checkGrade(signGrade)), execGrade(checkGrade(execGrade))
{
	if (MESSAGE)
		std::cout << PINK "Form Constructor (int, int) called." DEFAULT << std::endl;
}
catch (Form::GradeTooLowException &e)
{
	std::cout << "TEST" << std::endl;
	throw (e);
}


Form::Form(std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(checkGrade(signGrade)), execGrade(checkGrade(execGrade))
{
	if (MESSAGE)
		std::cout << PINK "Form Constructor (string, int, int) called." DEFAULT << std::endl;
}

Form::Form(Form const &rhs) : name(rhs.name), isSigned(false), signGrade(rhs.signGrade), execGrade(rhs.execGrade)
{
	if (MESSAGE)
		std::cout << PINK "Form Copy Constructor called." DEFAULT << std::endl;
}

Form::~Form()
{
	if (MESSAGE)
		std::cout << BLUE "Form Destructor called." DEFAULT << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "Form Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->isSigned = rhs.isSigned;
	return (*this);
}

int	Form::checkGrade(int grade) const
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return (grade);
}

std::string const	Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

int	Form::getExecGrade() const
{
	return (this->execGrade);
}

void	Form::beSigned(Bureaucrat signer)
{
	if (this->isSigned)
		std::cout << this->name << " is already signed." << std::endl;
	else if (signer.getGrade() <= this->signGrade && !this->isSigned)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return("Grade is too high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return("Grade is too low.");
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << ": signGrade " << rhs.getSignGrade() << ", execGrade " << rhs.getExecGrade() << ", is signed: " << rhs.getIsSigned();
	return (o);
}
