/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:55:10 by smischni          #+#    #+#             */
/*   Updated: 2023/01/15 19:32:05 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << PINK "ScavTrap Default Constructor called." DEFAULT << std::endl;
	this->setHP(100);
	this->setEP(50);
	this->setDamage(20);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << PINK "ScavTrap Name Constructor called." DEFAULT << std::endl;
	this->setName(name);
	this->setHP(100);
	this->setEP(50);
	this->setDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << PINK "ScavTrap Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << BLUE "ScavTrap Destructor called." DEFAULT << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << YELLOW "ScavTrap Copy Assignment Operator called." DEFAULT << std::endl;
	(ClapTrap)*this = (ClapTrap)rhs;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << std::endl;
	if (this->getEP() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
		this->setEP(this->getEP() - 1);
	}
	else
		std::cout << "ScavTrap " << this->getName() << " cannot attack since it has 0 energy points." << std::endl;
	std::cout << "HP: " << this->getHP() << "\tEP: " << this->getEP() << std::endl;
	std::cout << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << std::endl;
	std::cout << "ScavTrap " << this->getName() << " is now in gatekeeper mode." << std::endl;
	std::cout << std::endl;
}
