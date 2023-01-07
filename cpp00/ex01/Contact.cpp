/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:03:45 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 16:20:38 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return;
}

void	Contact::display_contact(void)
{
	std::cout << "First name: " << first << std::endl;
	std::cout << "Last name: " << last << std::endl;
	std::cout << "Nickname: " << nick << std::endl;
	std::cout << "Phone number: " << phone << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

void	Contact::set_idx(int idx)
{
	index = idx;
}

void	Contact::set_first(void)
{
	std::string	input;
	
	std::cout << "First name: ";
	getline(std::cin, input);
	first = input;
}

void	Contact::set_last(void)
{
	std::string	input;
	
	std::cout << "Last name: ";
	getline(std::cin, input);
	last = input;
}

void	Contact::set_nick(void)
{
	std::string	input;
	
	std::cout << "Nickname: ";
	getline(std::cin, input);
	nick = input;
}

void	Contact::set_phone(void)
{
	std::string	input;
	
	std::cout << "Phone number: ";
	getline(std::cin, input);
	phone = input;
}

void	Contact::set_secret(void)
{
	std::string	input;
	
	std::cout << "Darkest secret: ";
	getline(std::cin, input);
	secret = input;
}
