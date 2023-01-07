/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:40:26 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 19:16:03 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	input;
	
	book.set_idx(0);
	std::cout << std::endl;
	std::cout << PINK "Welcome to the shittiest phonebook software ever." DEFAULT << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::cout << PINK "Ugh. Why are you even here?" DEFAULT << std::endl;
		std::cout << BLUE "ADD | SEARCH | EXIT" DEFAULT << std::endl;
		if (!getline(std::cin, input))
			break ;
		if (input == "ADD")
			book.add_contact();
		else if (input == "SEARCH")
			book.display_phonebook();
		else if (input == "EXIT")
		{
			std::cout << PINK "Good decision. I will lose your contacts anyways." DEFAULT << std::endl;
			return (0);
		}
		else
			std::cout << PINK "Try again, loser." DEFAULT << std::endl;
	}
	if (std::cin.eof())
		std::cout << std::endl << PINK "Wow. Is typing EXIT too much to ask for?!" DEFAULT << std::endl;
	else
	{
		std::cout << PINK "Error. Told you this was shitty." DEFAULT << std::endl;
		return (1);
	}
	return (0);
}
