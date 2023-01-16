/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:06:38 by smischni          #+#    #+#             */
/*   Updated: 2023/01/16 19:46:35 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : hp(10), ep(10), damage(0)
{
	std::cout << PINK "ClapTrap Default Constructor called." DEFAULT << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), damage(0)
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
	std::cout << YELLOW "ClapTrap Copy Assignment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.getName();
		this->hp = rhs.getHP();
		this->ep = rhs.getEP();
		this->damage = rhs.getDamage();
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << std::endl;
	if (this->ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->ep--;
	}
	else
		std::cout << "ClapTrap " << this->name << " cannot attack since it has 0 energy points." << std::endl;
	std::cout << "HP: " << this->hp << "\tEP: " << this->ep << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::endl;
	if (this->hp >= amount)
	{
		this->hp -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " hit points damage." << std::endl;
	}
	else if (this->hp > 0)
	{
		std::cout << "ClapTrap " << this->name << " takes " << this->hp << " hit points damage." << std::endl;
		this->hp = 0;
	}
	std::cout << "HP: " << this->hp << "\tEP: " << this->ep << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << std::endl;
	if (this->ep > 0)
	{
		this->hp += amount;
		this->ep--;
		std::cout << "ClapTrap " << this->name << " repaired itself by " << amount << " hit points." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " cannot repair itself since it has 0 energy points." << std::endl;
	std::cout << "HP: " << this->hp << "\tEP: " << this->ep << std::endl;
	std::cout << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHP(void) const
{
	return (this->hp);
}

unsigned int	ClapTrap::getEP(void) const
{
	return (this->ep);
}

unsigned int	ClapTrap::getDamage(void) const
{
	return (this->damage);
}
