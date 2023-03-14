/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:56:10 by smischni          #+#    #+#             */
/*   Updated: 2023/03/14 16:43:20 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _isReady(false)
{
	if (MESSAGE)
		std::cout << PINK "BitcoinExchange Default Constructor called." DEFAULT << std::endl;
	
	std::ifstream	database;
	database.open("data.csv", std::ifstream::in);
	if (!database.is_open())
	{
		std::cerr << RED "ERROR: " DEFAULT << "Failed to open database. Please provide data.csv file." << std::endl;
		return ;
	}
	
	std::string	line;
	std::string	date;
	double		price;
	size_t		pos;
	
	getline(database, line);//skip first line
	while (getline(database, line))
	{
		pos = line.find(',', 0);
		if (pos == std::string::npos)
		{
			std::cerr << RED "ERROR: " DEFAULT << "Invalid data format in data.csv. Please provide correct data.csv file." << std::endl;
			return ;
		}	
		date = line.substr(0, pos);
		line.erase(0, pos + 1);
		price = atof(line.c_str());
		_priceHistory.insert(std::make_pair(date, price));
	}
	database.close();
	_isReady = true;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "BitcoinExchange Copy Constructor called." DEFAULT << std::endl;

	if (this != &rhs)
	{
		this->_priceHistory = rhs._priceHistory;
		this->_isReady = rhs._isReady;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	if (MESSAGE)
		std::cout << BLUE "BitcoinExchange Destructor called." DEFAULT << std::endl;
}

BitcoinExchange	BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "BitcoinExchange Copy Assignment Operator called." DEFAULT << std::endl;

	if (this != &rhs)
	{
		this->_priceHistory = rhs._priceHistory;
		this->_isReady = rhs._isReady;
	}
	return (*this);
}

bool	BitcoinExchange::isReady() const
{
	return this->_isReady;
}

float	BitcoinExchange::getPrice(std::string date) const
{
	std::map<std::string, double>::const_iterator it = _priceHistory.find(date);
	if (it == _priceHistory.end())
		return -1;
	return it->second;
}

bool	isValidDate(std::string date)
{
	for (int i = 0; i < date.length(); i++)
	{
		if (date[i] != '-' && isdigit(date[i] == 0))
			return false;
	}
	
	//check the year
	size_t pos = date.find('-', 0);
	if (pos == std::string::npos || pos > 4 || pos == 0)
		return false;
	int year = atoi(date.substr(0, pos).c_str());
	date.erase(0, pos + 1);

	//check the month
	pos = date.find('-', 0);
	if (pos == std::string::npos || pos != 2)
		return false;
	int month = atoi(date.substr(0, pos).c_str());
	if (month < 1 || month > 12)
		return false;
	date.erase(0, pos + 1);

	//check the day
	if (date.empty() || date.length() > 2)
		return false;
	int day = atoi(date.c_str());
	if (day > 32 || day < 1)
		return false;
	if (day == 31 && month < 8 && month % 2 != 1)
		return false;
	if (day == 31 && month >= 8 && month % 2 != 0)
		return false;
	if (day > 28 && month == 2)
	{
		if (day > 29 || year % 4 != 0)
			return false;
	}
	return true;
}
