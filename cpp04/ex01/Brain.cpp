/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:13:14 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 16:35:31 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << PINK "Brain Default Constructor called." DEFAULT << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 10 == 0)
			this->ideas[i] = "you KICK miette?";
		else if (i % 12 == 1)
			this->ideas[i] = "you kick her body like the football?";
		else if (i % 12 == 2)
			this->ideas[i] = "oh!";
		else if (i % 12 == 3)
			this->ideas[i] = "oh!";
		else if (i % 12 == 4)
			this->ideas[i] = "jail for mother!";
		else if (i % 12 == 5)
			this->ideas[i] = "jail for mother for One Thousand Years!!!!";
		else if (i % 12 == 6)
			this->ideas[i] = "Father is …evil?";
		else if (i % 12 == 7)
			this->ideas[i] = "Father is unyielding?";
		else if (i % 12 == 8)
			this->ideas[i] = "Father is incapable of love?";
		else if (i % 12 == 9)
			this->ideas[i] = "I am running away.";
		else if (i % 12 == 10)
			this->ideas[i] = "I am packing my little rucksack and going out to explore the world as a lone vagabond.";
		else if (i % 12 == 11)
			this->ideas[i] = "I can no longer thrive in this household.";
	}
}

Brain::Brain(Brain const &src)
{
	std::cout << PINK "Brain Copy Constructor called." DEFAULT << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << BLUE "Brain Destructor called." DEFAULT << std::endl;
}

Brain	&Brain::operator=(Brain const &src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.getIdea(i);
}

void	Brain::setIdea(std::string newIdea, int index)
{
	this->ideas[index] = newIdea;
}

std::string	Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}
