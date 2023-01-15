/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:07:21 by smischni          #+#    #+#             */
/*   Updated: 2023/01/15 19:17:25 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"

class ClapTrap {
	private:
		std::string		name;
		unsigned int	hp;
		unsigned int	ep;
		unsigned int	damage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &rhs);
		
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName(void) const;
		void			setName(std::string name);
		unsigned int	getHP(void) const;
		void			setHP(unsigned int amount);
		unsigned int	getEP(void) const;
		void			setEP(unsigned int amount);
		unsigned int	getDamage(void) const;
		void			setDamage(unsigned int damage);
};

#endif
