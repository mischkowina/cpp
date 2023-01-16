/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:49:45 by smischni          #+#    #+#             */
/*   Updated: 2023/01/16 19:25:29 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << PINK "DiamondTrap Default Constructor called." DEFAULT << std::endl;
	this->setHP(100);
	this->setEP(50);
	this->setDamage(30);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << PINK "DiamondTrap Name Constructor called." DEFAULT << std::endl;
	this->setHP(100);
	this->setEP(50);
	this->setDamage(30);

}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	std::cout << PINK "DiamondTrap Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << BLUE "DiamondTrap Destructor called." DEFAULT << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << YELLOW "DiamondTrap Copy Assignment Operator called." DEFAULT << std::endl;
	(ClapTrap)*this = (ClapTrap)rhs;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap Desmond asks \"Who am I? Am I " << this->name << " or am I " << ClapTrap::getName() << "\"?" << std::endl;
}
