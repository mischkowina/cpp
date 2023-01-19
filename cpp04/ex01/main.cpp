/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:48 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 17:23:34 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << YELLOW "*** Creating Original Cat & Dog ***" DEFAULT << std::endl;
		const Cat og_cat;
		const Dog og_dog;
		std::cout << YELLOW "*** Creating Animal array and filling it with copies of OG Cat / Dog ***" DEFAULT << std::endl;
		Animal *animals[10];

		for (int i = 0; i < 5; i++)
		{
			animals[i] = new Dog(og_dog);
			animals[i + 5] = new Cat(og_cat);
		}
		std::cout << YELLOW "*** Delete Animal array ***" DEFAULT << std::endl;
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	return (0);
}
