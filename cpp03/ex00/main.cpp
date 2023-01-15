/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:07:23 by smischni          #+#    #+#             */
/*   Updated: 2023/01/15 16:33:45 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	greg("Greg");

	greg.attack("Joe");
	greg.attack("Ross");
	greg.attack("Chandler");
	greg.attack("Ross");
	while(greg.getHP() > 0)
		greg.takeDamage(6);
	for (int i = 0; i < 7; i++)
		greg.beRepaired(1);
	greg.attack("Ross");
	return (0);
}
