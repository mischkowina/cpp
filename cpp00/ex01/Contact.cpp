/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:03:45 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 18:35:28 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::display_contact(void)
{
	std::cout << BLUE "First name:\t" DEFAULT << first << std::endl;
	std::cout << BLUE "Last name:\t" DEFAULT << last << std::endl;
	std::cout << BLUE "Nickname:\t" DEFAULT << nick << std::endl;
	std::cout << BLUE "Phone number:\t" DEFAULT << phone << std::endl;
	std::cout << BLUE "Darkest secret:\t" DEFAULT << secret << std::endl;
}

void	Contact::set_idx(int idx)
{
	index = idx;
}

void	Contact::set_first(void)
{
	std::string	input;
	
	while (input.length() < 1)
	{
		std::cout << BLUE "First name: " DEFAULT;
		getline(std::cin, input);
		if (input.length() < 1)
			std::cout << PINK "Cannot be empty, you fool!" DEFAULT << std::endl;
	}
	first = input;
}

std::string	Contact::get_first(void)
{
	std::string	trimmed;
	
	trimmed = first;
	if (trimmed.length() > 10)
	{
		trimmed.resize(9);
		trimmed.append(".");
	}
	return (trimmed);
}

void	Contact::set_last(void)
{
	std::string	input;
	
	while (input.length() < 1)
	{
		std::cout << BLUE "Last name: " DEFAULT;
		getline(std::cin, input);
		if (input.length() < 1)
			std::cout << PINK "Cannot be empty, you fool!" DEFAULT << std::endl;
	}
	last = input;
}

std::string	Contact::get_last(void)
{
	std::string	trimmed;
	
	trimmed = last;
	if (trimmed.length() > 10)
	{
		trimmed.resize(9);
		trimmed.append(".");
	}
	return (trimmed);
}

void	Contact::set_nick(void)
{
	std::string	input;
	
	while (input.length() < 1)
	{
		std::cout << BLUE "Nickname: " DEFAULT;
		getline(std::cin, input);
		if (input.length() < 1)
			std::cout << PINK "Cannot be empty, you fool!" DEFAULT << std::endl;
	}
	nick = input;
}

std::string	Contact::get_nick(void)
{
	std::string	trimmed;
	
	trimmed = nick;
	if (trimmed.length() > 10)
	{
		trimmed.resize(9);
		trimmed.append(".");
	}
	return (trimmed);
}

void	Contact::set_phone(void)
{
	std::string	input;
	
	while (input.length() < 1)
	{
		std::cout << BLUE "Phone number: " DEFAULT;
		getline(std::cin, input);
		if (input.length() < 1)
			std::cout << PINK "Cannot be empty, you fool!" DEFAULT << std::endl;
	}
	phone = input;
}

void	Contact::set_secret(void)
{
	std::string	input;
	
	while (input.length() < 1)
	{
		std::cout << BLUE "Darkest secret: " DEFAULT;
		getline(std::cin, input);
		if (input.length() < 1)
			std::cout << PINK "Cannot be empty, you fool!" DEFAULT << std::endl;
	}
	secret = input;
}
