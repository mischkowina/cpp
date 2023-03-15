/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:56:07 by smischni          #+#    #+#             */
/*   Updated: 2023/03/15 12:09:37 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "ERROR: " DEFAULT << "Needs exactly one input parameter (infile)." << std::endl;
		return 1;
	}
	
	BitcoinExchange	btc;

	//open infile
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
	
	//skip first line and check for empty file
	getline(input, line);
	if (input.eof())
	{
		std::cerr << RED "ERROR: " DEFAULT << "No data entries in infile." << std::endl;
		return 1;
	}
	
	//read and process line by line
	while (getline(input, line))
	{
		pos = line.find(" | ", 0);
		//check right input format
		if (pos == std::string::npos)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Bad input: " << line << std::endl;
			continue ;
		}
		
		//get date and check if it is valid
		date = line.substr(0, pos);
		if (isValidDate(date) == false)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Bad input: " << line << std::endl;
			continue ;
		}
		
		//check if rest of the line is a valid number
		line.erase(0, pos + 3);
		if (!isValidNumber(line))
		{
			std::cerr << RED "ERROR: " DEFAULT << "Bad input: " << date << " | " << line << std::endl;
			continue ;
		}
		
		//convert into number, check if it is within the specified range 0 - 1000
		amount = atof(line.c_str());
		if (amount > 1000)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Too large a number" << std::endl;
			continue ; 
		}
		else if (amount < 0)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Not a positive number" << std::endl;
			continue ; 
		}
		
		//get the price for that date and catch exception if the date is before the first entry
		try
		{
			price = btc.getPrice(date);
		}
		catch (std::exception &e)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Date is too early. Data base starts at " << btc.getFirstEntryDate() << std::endl;
			continue ; 
		}
		
		//output the result
		std::cout << date << " => " << amount << " = " << amount * price << std::endl;
	}
	
	return 0;
}
