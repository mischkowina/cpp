/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:43 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 15:54:27 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"

class WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal(void);

		WrongAnimal	&operator=(WrongAnimal const &rhs);

		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif
