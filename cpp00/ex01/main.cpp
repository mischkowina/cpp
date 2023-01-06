/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:40:26 by smischni          #+#    #+#             */
/*   Updated: 2023/01/06 18:49:36 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	input;
	
	std::cout << std::endl;
	std::cout << "Welcome to the shittiest phonebook software ever." << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::cout << "Ugh. Why are you even here?" << std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		if (!getline(std::cin, input))
			break ;
		if (input == "ADD")
			std::cout << "Congrats, you can write ADD" << std::endl;//add function
		else if (input == "SEARCH")
			std::cout << "Congrats, you can write SEARCH" << std::endl;//search function
		else if (input == "EXIT")
		{
			std::cout << "Good decision. I would loose your contacts anyways." << std::endl;
			return (0);
		}
		else
			std::cout << "Try again, loser." << std::endl;
	}
	if (std::cin.eof())
		std::cout << std::endl << "Wow. Is typing EXIT too much to ask for?!" << std::endl;
	else
	{
		std::cout << "Error. Told you this was shitty." << std::endl;
		return (1);
	}
	return (0);
}
