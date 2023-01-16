/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:17:47 by smischni          #+#    #+#             */
/*   Updated: 2023/01/16 13:30:12 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << PINK "FragTrap Default Constructor called." DEFAULT << std::endl;
	this->setHP(100);
	this->setEP(100);
	this->setDamage(30);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << PINK "FragTrap Name Constructor called." DEFAULT << std::endl;
	this->setName(name);
	this->setHP(100);
	this->setEP(100);
	this->setDamage(30);
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << PINK "FragTrap Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << BLUE "FragTrap Destructor called." DEFAULT << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << YELLOW "FragTrap Copy Assignment Operator called." DEFAULT << std::endl;
	(ClapTrap)*this = (ClapTrap)rhs;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << std::endl;
	std::cout << "FragTrap " << this->getName() << " yells \"Yeah man! High Five, Bro!\" and raises his hand." << std::endl;
	std::cout << std::endl;
}
