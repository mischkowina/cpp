/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:07:23 by smischni          #+#    #+#             */
/*   Updated: 2023/01/16 13:32:42 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	{
		std::cout << std::endl << GREEN "*** Test of FragTrap ****" DEFAULT << std::endl << std::endl;
		
		FragTrap	fred("Fred");

		fred.attack("Joe");
		fred.takeDamage(21);
		fred.beRepaired(7);
		fred.highFiveGuys();
	}
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
		std::cout << std::endl << GREEN "*** Test of FragTrap assignment to ClapTrap ***" DEFAULT << std::endl;

		ClapTrap	dude;
		FragTrap	harl("Harl");

		dude = harl;

		dude.attack("Ross");
		dude.takeDamage(7);
		dude.beRepaired(3);
	}
	return (0);
}
