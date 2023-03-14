/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:56:07 by smischni          #+#    #+#             */
/*   Updated: 2023/03/14 17:16:49 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "ERROR: " DEFAULT << "Only one input parameter (infile) allowed." << std::endl;
		return 1;
	}
	
	BitcoinExchange	btc;
	std::ifstream	input;
	std::string		filename(argv[1]);

	input.open(filename, std::ifstream::in);
	if (!input.is_open())
	{
		std::cerr << RED "ERROR: " DEFAULT << "Failed to open infile." << std::endl;
		return 1;
	}

	std::string	line;
	std::string	date;
	size_t		pos;
	double		amount;
	double		price;
	
	int			i = 0;
	
	while (getline(input, line))
	{
		pos = line.find(" | ", 0);
		if (pos == std::string::npos)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Bad input: " << line << std::endl;
			continue ;
		}
		date = line.substr(0, pos);
		if (isValidDate(date) == false)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Bad input: " << line << std::endl;
			continue ;
		}
		line.erase(0, pos + 3);
		
		// check if line is only digit afterwards
		
		pos = line.find('.', 0);
		if (pos == std::string::npos)
			amount = atoi(line.c_str());
		else
			amount = atof(line.c_str());

		price = btc.getPrice(date);
		if (price == -1)
		{
			std::cerr << RED "ERROR: " DEFAULT << "No match for this date: " << date << std::endl;
			continue ;
		}
		
		std::cout << date << " => " << amount <<
	}
	
	return 0;
}
