/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:04:03 by smischni          #+#    #+#             */
/*   Updated: 2023/02/02 16:09:48 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	if (MESSAGE)
		std::cout << PINK "Data Default Constructor called." DEFAULT << std::endl;
}

Data::Data(Data const &rhs) : my_darkest_secret(rhs.my_darkest_secret)
{
	if (MESSAGE)
		std::cout << PINK "Data Copy Constructor called." DEFAULT << std::endl;
}

Data::~Data()
{
	if (MESSAGE)
		std::cout << BLUE "Data Destructor called." DEFAULT << std::endl;
}

Data	&Data::operator=(Data const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "Data Copy Assigment Operator called." DEFAULT << std::endl;
	this->my_darkest_secret = rhs.my_darkest_secret;
	return (*this);
}

void	Data::setMyDarkestSecret(std::string secret)
{
	this->my_darkest_secret = secret;
}

std::string	Data::getMyDarkestSecret() const
{
	return(my_darkest_secret);
}
