/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:53:09 by smischni          #+#    #+#             */
/*   Updated: 2023/01/10 14:12:36 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}

HumanB::~HumanB(void)
{
	
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
