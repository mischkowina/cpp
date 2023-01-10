/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:52:20 by smischni          #+#    #+#             */
/*   Updated: 2023/01/10 16:08:22 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	
}

Weapon::Weapon(std::string _type) : type(_type)
{
	
}

Weapon::~Weapon(void)
{
	
}

const std::string	&Weapon::getType(void)
{
	const std::string	&ref = this->type;

	return (ref);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
