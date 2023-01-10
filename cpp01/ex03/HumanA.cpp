/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:52:49 by smischni          #+#    #+#             */
/*   Updated: 2023/01/10 16:00:02 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//no standard constructor allowed, since it wouldn't initialize _weapon:
// HumanA::HumanA(void)
// {
	
// }

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	
}

HumanA::~HumanA(void)
{
	
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

