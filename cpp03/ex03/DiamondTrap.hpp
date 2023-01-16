/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:44:42 by smischni          #+#    #+#             */
/*   Updated: 2023/01/16 19:03:28 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public	FragTrap {
	private:
		std::string	name;
	
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap	(DiamondTrap const &src);
		~DiamondTrap(void);
		
		DiamondTrap	&operator=(DiamondTrap const &rhs);
		
		using ScavTrap::attack;
		void	whoAmI(void);
};

#endif
