/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:02:46 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 19:21:57 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::set_idx(int idx)
{
	cur_idx = idx;
}

void	PhoneBook::add_contact(void)
{
	Contact	contact;
	int		idx;
	
	std::cout << PINK "Okay, let's get it over with." DEFAULT << std::endl;
	contact.set_first();
	contact.set_last();
	contact.set_nick();
	contact.set_phone();
	contact.set_secret();
	if (cur_idx == 0)
		idx = 0;
	else
		idx = cur_idx % 8;
	contact.set_idx(idx);
	contacts[idx] = contact;
	cur_idx++;
}

void	PhoneBook::display_phonebook(void)
{
	std::string	input;
	int			idx;
	
	if (cur_idx == 0)
	{
		std::cout << PINK "The phonebook is empty, you idiot. Add contacts first." DEFAULT << std::endl;
		return ;
	}
	std::cout << PINK "There you go. How hard can it be to remember 8 contacts?" BLUE << std::endl;
	std::cout << '|';
	std::cout << std::setw(10) << "INDEX" << '|';
	std::cout << std::setw(10) << "FIRST NAME" << '|';
	std::cout << std::setw(10) << "LAST NAME" << '|';
	std::cout << std::setw(10) << "NICKNAME" << '|' << std::endl;
	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;
	for (int i = 0; i < 8 && i < cur_idx; i++)
	{
		std::cout << '|' << DEFAULT;
		std::cout << std::setw(10) << (i + 1);
		std::cout << BLUE << '|' << DEFAULT;
		std::cout << std::setw(10) << contacts[i].get_first();
		std::cout << BLUE << '|' << DEFAULT;
		std::cout << std::setw(10) << contacts[i].get_last();
		std::cout << BLUE << '|' << DEFAULT;
		std::cout << std::setw(10) << contacts[i].get_nick();
		std::cout << BLUE << '|' << std::endl;
	}
	std::cout << PINK "For which contact do you want the details?" DEFAULT << std::endl;
	while (1)
	{
		std::cout << BLUE "Index: " DEFAULT;
		getline(std::cin, input);
		idx = std::atoi(input.c_str());
		if (idx > 0 && idx < 9 && idx <= cur_idx)
		{
			contacts[idx - 1].display_contact();
			break ;
		}	
		else
			std::cout << PINK "Jesus... give me a valid index already." DEFAULT << std::endl;
	}
}
