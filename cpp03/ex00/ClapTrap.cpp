/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:06:38 by smischni          #+#    #+#             */
/*   Updated: 2023/01/14 18:39:31 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << PINK "ClapTrap Default Constructor called." DEFAULT << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout << PINK "ClapTrap Name Constructor called." DEFAULT << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << PINK "ClapTrap Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE "ClapTrap Destructor called." DEFAULT << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		//getter and setter for attributes
	}
}
