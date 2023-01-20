/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:48 by smischni          #+#    #+#             */
/*   Updated: 2023/01/20 18:57:54 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		std::cout << GREEN "Code from ex01 - still works :-)" DEFAULT << std::endl;
		std::cout << YELLOW "*** Creating Original Cat & Dog ***" DEFAULT << std::endl;
		Cat og_cat;
		Dog og_dog;
		std::cout << YELLOW "*** Creating Animal array and filling it with copies of OG Cat / Dog ***" DEFAULT << std::endl;
		AAnimal *animals[10];

		for (int i = 0; i < 5; i++)
		{
			animals[i] = new Dog(og_dog);
			animals[i + 5] = new Cat(og_cat);
		}

		std::cout << YELLOW "*** Changing idea of original Cat ***" DEFAULT << std::endl;
		std::cout << "Original idea[5]: " << og_cat.getIdea(5) << std::endl;
		og_cat.setIdea("GIVE ME FOOD HUMAN", 5);
		std::cout << "New idea[5]: " << og_cat.getIdea(5) << std::endl;
		std::cout << "Adress of brain: " << &(og_cat.getBrain()) << std::endl;
		
		std::cout << YELLOW "*** Checking the same idea of CopyCats ***" DEFAULT << std::endl;
		for (int i = 5; i < 10; i++)
		{
			std::cout << (*(Cat *)(animals[i])).getIdea(5) << std::endl;
			std::cout << "Adress of brain: " << &((*(Cat *)(animals[i])).getBrain()) << std::endl;
		}
		
		std::cout << YELLOW "*** Delete Animal array ***" DEFAULT << std::endl;
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	{
		std::cout << GREEN "AAnimal can't be instantiated:" DEFAULT << std::endl;
		// can't be instantiated
		// AAnimal *a = new AAnimal();
		AAnimal *b = new Dog();
		AAnimal *c = new Cat();
		
		b->makeSound();
		c->makeSound();

		delete b;
		delete c;
	}
	return (0);
}
