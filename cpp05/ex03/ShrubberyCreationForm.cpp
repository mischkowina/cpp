/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:00:00 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 15:43:30 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "John Doe")
{
	if (MESSAGE)
		std::cout << PINK "ShrubberyCreationForm Default Constructor called." DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm(rhs)
{
	if (MESSAGE)
		std::cout << PINK "ShrubberyCreationForm Copy Constructor called." DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	if (MESSAGE)
		std::cout << PINK "ShrubberyCreationForm Constructor (string) called." DEFAULT << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (MESSAGE)
		std::cout << BLUE "ShrubberyCreationForm Destructor called." DEFAULT << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "ShrubberyCreationForm Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
		this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

void	ShrubberyCreationForm::execution() const
{
	std::ofstream	ofs;

	ofs.open(this->getTarget() + "_shrubbery");
	if (!ofs.is_open())
	{
		throw FailedOpeningOutfileException();
	}
	ofs << "             ,@@@@@@@," << std::endl;
	ofs << "    ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "    |o|        | |         | |" << std::endl;
	ofs << "    |.|        | |         | |" << std::endl;
	ofs << " \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	ofs.close();
}

const char	*ShrubberyCreationForm::FailedOpeningOutfileException::what() const throw()
{
	return ("Outfile could not be opened.");
}
