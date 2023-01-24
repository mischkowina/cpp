/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:24 by smischni          #+#    #+#             */
/*   Updated: 2023/01/24 13:50:09 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << PINK "MateriaSource Default Constructor called." DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
	std::cout << PINK "MateriaSource Copy Constructor called." DEFAULT << std::endl;
	*this = rhs;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << BLUE "MateriaSource Destructor called." DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
			delete materias[i];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	std::cout << PINK "MateriaSource Copy Assigment Operator called." DEFAULT << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->materias[i])
				delete this->materias[i];
			if (rhs.materias[i])
				this->materias[i] = rhs.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			materias[i] = m;
			return ;
		}
	}
	std::cout << "Full capacity: not possible to learn another Marteria" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i]->getType().compare(type))
			return (materias[i]->clone());
	}
	std::cout << "No such Materia known by MateriaSource." << std::endl;
	return (0);
}
