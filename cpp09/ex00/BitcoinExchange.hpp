/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:56:11 by smischni          #+#    #+#             */
/*   Updated: 2023/03/16 14:02:18 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define DEFAULT "\033[0m"
# define RED "\033[31m"

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <exception>
# include <stdexcept>
# include <cstdlib>
# include <utility>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_priceHistory;
		bool							_isValid;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &rhs);
		~BitcoinExchange();
		BitcoinExchange	operator=(BitcoinExchange const &rhs);

		bool		isValid() const;
		float		getPrice(std::string date) const;
		std::string	getFirstEntryDate() const;
};

bool	isValidDate(std::string date);
bool	isValidNumber(std::string nbr);

#endif
