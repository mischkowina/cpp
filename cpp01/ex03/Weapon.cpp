/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:52:20 by smischni          #+#    #+#             */
/*   Updated: 2023/01/10 13:53:34 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
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
