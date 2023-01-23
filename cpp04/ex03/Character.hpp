/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:16:40 by smischni          #+#    #+#             */
/*   Updated: 2023/01/23 11:52:07 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string		name;
		AMateria		*inventory[4];
		AMateria		**unequipped;
		unsigned int	unequip_counter;
	
	public:
		Character(void);
		Character(std::string name);
		Character(Character const &rhs);
		~Character(void);

		Character &operator=(Character const &rhs);
		
		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
