/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:56:10 by smischni          #+#    #+#             */
/*   Updated: 2023/03/15 15:26:24 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _isValid(false)
{
	std::ifstream	database;
	database.open("data.csv", std::ifstream::in);
	if (!database.is_open())
	{
		std::cout << RED "ERROR: " DEFAULT << "Failed to open database. Please provide data.csv file." << std::endl;
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
			std::cout << RED "ERROR: " DEFAULT << "Invalid data entry (format) in data.csv. Please provide correct data.csv file." << std::endl;
			return ;
		}	
		date = line.substr(0, pos);
		line.erase(0, pos + 1);
		if (!isValidDate(date) || !isValidNumber(line))
		{
			std::cout << RED "ERROR: " DEFAULT << "Invalid data entry (date / number format) in data.csv. Please provide correct data.csv file." << std::endl;
			return ;
		}
		price = atof(line.c_str());
		if (price < 0)
		{
			std::cout << RED "ERROR: " DEFAULT << "Invalid data entry (date / number format) in data.csv. Please provide correct data.csv file." << std::endl;
			return ;
		}
		_priceHistory.insert(std::make_pair(date, price));
	}
	database.close();
	_isValid = true;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_priceHistory = rhs._priceHistory;
		this->_isValid = rhs._isValid;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange	BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_priceHistory = rhs._priceHistory;
		this->_isValid = rhs._isValid;
	}
	return (*this);
}

bool	BitcoinExchange::isValid() const
{
	return this->_isValid;
}

float	BitcoinExchange::getPrice(std::string date) const
{
	std::map<std::string, double>::const_iterator it = _priceHistory.lower_bound(date);
	if (it == _priceHistory.begin())
		throw std::exception();
	else if (it == _priceHistory.end() || date != it->first)
		return (--it)->second;
	return it->second;
}

std::string	BitcoinExchange::getFirstEntryDate() const
{
	return _priceHistory.begin()->first;
}

bool	isValidDate(std::string date)
{
	for (int i = 0; i < date.length(); i++)
	{
		if (date[i] != '-' && isdigit(date[i]) == 0)
			return false;
	}
	
	//check the year
	size_t pos = date.find('-', 0);
	if (pos == std::string::npos || pos == 0)
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
	if (day > 31 || day < 1)
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

bool	isValidNumber(std::string nbr)
{
	int	nbr_dots = 0;
	
	for (int i = 0; i < nbr.length(); i++)
	{
		if (i == 0 && nbr[i] == '-')
			continue;
		if (nbr[i] != '.' && isdigit(nbr[i]) == 0)
			return false;
		if (nbr[i] == '.')
			nbr_dots++;
	}
	if (nbr_dots > 1)
		return false;
	return true;
}
