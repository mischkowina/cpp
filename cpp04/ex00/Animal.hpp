/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:05:08 by smischni          #+#    #+#             */
/*   Updated: 2023/01/19 16:06:50 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"

class Animal {
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(Animal const &src);
		virtual	~Animal(void);

		Animal	&operator=(Animal const &rhs);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
