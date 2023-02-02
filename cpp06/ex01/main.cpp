/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:32:37 by smischni          #+#    #+#             */
/*   Updated: 2023/02/02 16:21:06 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << YELLOW "***** Creating Data* object d *****" DEFAULT << std::endl;
	Data	*d = new Data();
	
	d->setMyDarkestSecret("I love big butts and I cannot lie.");
	std::cout << "Address of d: " << d << std::endl;
	std::cout << "Darkest secret of d: " << d->getMyDarkestSecret() << std::endl;
	
	std::cout << YELLOW "***** Serialize it, get uintptr_t value and set d to NULL *****" DEFAULT << std::endl;
	
	uintptr_t uip = Serializer::serialize(d);
	std::cout << "uintptr_t uip = " << uip << std::endl;
	
	d = NULL;

	std::cout << YELLOW "***** Create Data* object e & assign it return value of deserialize(uintptr_t) *****" DEFAULT << std::endl;
	Data *e;
	e = Serializer::deserialize(uip);
	std::cout << "Address of e: " << e << std::endl;
	std::cout << "Darkest secret of e: " << e->getMyDarkestSecret() << std::endl;

	delete e;
	
	std::cout << std::endl;
	return (0);
}
