/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:07:23 by smischni          #+#    #+#             */
/*   Updated: 2023/01/16 13:06:10 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << std::endl << GREEN "*** Test of ScavTrap ****" DEFAULT << std::endl << std::endl;
		
		ScavTrap	josh("Josh");

		josh.attack("Joe");
		josh.takeDamage(12);
		josh.beRepaired(5);
		josh.guardGate();
	}
	{
		std::cout << std::endl << GREEN "*** Test of ClapTrap ***" DEFAULT << std::endl;
		
		ClapTrap	greg("Greg");

		greg.attack("Chandler");
		greg.takeDamage(4);
		greg.beRepaired(2);
	}
	{
		std::cout << std::endl << GREEN "*** Test of ScavTrap assignment to ClapTrap ***" DEFAULT << std::endl;

		ClapTrap	dude;
		ScavTrap	harl("Harl");

		dude = harl;

		dude.attack("Ross");
		dude.takeDamage(7);
		dude.beRepaired(3);
	}
	return (0);
}
