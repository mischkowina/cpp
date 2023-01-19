/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:48 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 15:43:39 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << YELLOW "*** Test of Animal, Cat & Dog ***" DEFAULT << std::endl;
		const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;

		meta->makeSound();
		i->makeSound();
		j->makeSound();

		delete meta;
		delete i;
		delete j;
		std::cout << std::endl;
	}
	{
		std::cout << YELLOW "*** Test of WrongAnimal & WrongCat ***" DEFAULT << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		const WrongCat* j = new WrongCat();

		std::cout << meta->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << j->getType() << std::endl;

		meta->makeSound();
		i->makeSound();
		j->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	return (0);
}
