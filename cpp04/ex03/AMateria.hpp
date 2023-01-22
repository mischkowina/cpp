/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:41:37 by smischni          #+#    #+#             */
/*   Updated: 2023/01/22 16:32:18 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"

class AMateria {
	protected:
		std::string	type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &rhs);
		virtual ~AMateria(void);

		AMateria	&operator=(AMateria const &rhs);

		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
