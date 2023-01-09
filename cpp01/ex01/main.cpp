/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:18:23 by smischni          #+#    #+#             */
/*   Updated: 2023/01/09 17:36:40 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

int	main(void)
{
	Zombie *zombie;

	zombie = zombieHorde(8, "Rüdiger");
	for (int i = 0; i < 8; i++)
	{
		zombie[i].announce();
		std::cout << "Adress: " << &zombie[i] << std::endl << std::endl;
	}
	delete [] zombie;
	
	return (0);
}
