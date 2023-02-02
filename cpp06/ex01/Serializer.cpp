/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:33:50 by smischni          #+#    #+#             */
/*   Updated: 2023/02/02 16:11:25 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	if (MESSAGE)
		std::cout << PINK "Serializer Default Constructor called." DEFAULT << std::endl;
}

Serializer::Serializer(Serializer const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "Serializer Copy Constructor called." DEFAULT << std::endl;
	(void)rhs;
}

Serializer::~Serializer()
{
	if (MESSAGE)
		std::cout << BLUE "Serializer Destructor called." DEFAULT << std::endl;
}

Serializer	&Serializer::operator=(Serializer const &rhs)
{
	if (MESSAGE)
		std::cout << PINK "Serializer Copy Assignment Operator called." DEFAULT << std::endl;
	(void)rhs;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
