/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:47 by smischni          #+#    #+#             */
/*   Updated: 2023/01/27 17:23:28 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Standard Form"), isSigned(false), signGrade(150), execGrade(150), target("John Doe")
{
	if (MESSAGE)
		std::cout << PINK "AForm Default Constructor called." DEFAULT << std::endl;
}

AForm::AForm(std::string name) : name(name), isSigned(false), signGrade(150), execGrade(150), target("John Doe")
{
	if (MESSAGE)
		std::cout << PINK "AForm Constructor (string) called." DEFAULT << std::endl;
}

AForm::AForm(int signGrade, int execGrade) : name("Standard Form"), isSigned(false), signGrade(checkGrade(signGrade)), execGrade(checkGrade(execGrade)), target("John Doe")
{
	if (MESSAGE)
		std::cout << PINK "AForm Constructor (int, int) called." DEFAULT << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(checkGrade(signGrade)), execGrade(checkGrade(execGrade)), target("John Doe")
{
	if (MESSAGE)
		std::cout << PINK "AForm Constructor (string, int, int) called." DEFAULT << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target) : name(name), isSigned(false), signGrade(checkGrade(signGrade)), execGrade(checkGrade(execGrade)), target(target)
{
	if (MESSAGE)
		std::cout << PINK "AForm Constructor (string, int, int, string) called." DEFAULT << std::endl;
}

AForm::AForm(AForm const &rhs) : name(rhs.name), isSigned(false), signGrade(rhs.signGrade), execGrade(rhs.execGrade), target(rhs.getTarget())
{
	if (MESSAGE)
		std::cout << PINK "AForm Copy Constructor called." DEFAULT << std::endl;
}

AForm::~AForm()
{
	if (MESSAGE)
		std::cout << BLUE "AForm Destructor called." DEFAULT << std::endl;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "AForm Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->isSigned = rhs.isSigned;
	return (*this);
}

int	AForm::checkGrade(int grade) const
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (grade < 1)
		throw AForm::GradeTooHighException();
	return (grade);
}

std::string const	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->isSigned);
}

int	AForm::getSignGrade() const
{
	return (this->signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->execGrade);
}

std::string const	AForm::getTarget() const
{
	return(this->target);
}

void	AForm::beSigned(Bureaucrat const &signer)
{
	if (this->isSigned)
		std::cout << this->name << " is already signed." << std::endl;
	else if (signer.getGrade() <= this->signGrade && !this->isSigned)
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->execGrade)
		throw GradeTooLowException();
	else
		this->execution();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed.");
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << rhs.getName() << ": signGrade " << rhs.getSignGrade() << ", execGrade " << rhs.getExecGrade() << ", is signed: " << rhs.getIsSigned();
	return (o);
}
