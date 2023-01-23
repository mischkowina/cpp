/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:16:38 by smischni          #+#    #+#             */
/*   Updated: 2023/01/23 17:55:23 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << PINK "Character Default Constructor called." DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	unequipped = new AMateria*[1];
	unequip_counter = 0;
}

Character::Character(std::string name) : name(name)
{
	std::cout << PINK "Character Name Constructor called." DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	unequipped = new AMateria*[1];
	unequip_counter = 0;
}

Character::Character(Character const &rhs)
{
	std::cout << PINK "Character Copy Constructor called." DEFAULT << std::endl;
	*this = rhs;
}

Character::~Character(void)
{
	std::cout << BLUE "Character Destructor called." DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}	
	for (int i = 0; i < unequip_counter; i++)
	{
		if (unequipped[i])
			delete unequipped[i];
	}
	delete [] unequipped;
}

Character	&Character::operator=(Character const &rhs)
{
	std::cout << PINK "Character Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "Full inventory: Materia cannot be equipped." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Invalid index, inventory can only hold 4 Marterias." << std::endl;
		return ;
	}
	else if (!inventory[idx])
	{
		std::cout << "There is nothing to be unequipped at this index." << std::endl;
		return ;
	}
	if (unequip_counter == 0)
	{
		unequipped[0] = inventory[idx];
		inventory[idx] = NULL;
	}
	else
	{
		AMateria **tmp = unequipped;
		unequipped = new AMateria*[unequip_counter + 1];
		for (int i = 0; i < unequip_counter; i++)
			unequipped[i] = tmp[i];
		unequipped[unequip_counter] = inventory[idx];
		inventory[idx] = NULL;
		delete [] tmp;
	}
	unequip_counter++;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index, inventory can only hold 4 Marterias." << std::endl;
		return ;
	}
	else if (!inventory[idx])
	{
		std::cout << "No Materia equipped at this index." << std::endl;
		return ;
	}
	else
		inventory[idx]->use(target);
}
