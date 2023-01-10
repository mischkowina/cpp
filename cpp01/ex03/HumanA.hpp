/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:52:50 by smischni          #+#    #+#             */
/*   Updated: 2023/01/10 14:08:47 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"
# include <iostream>

class HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);
		
		void	attack(void);
};

#endif
