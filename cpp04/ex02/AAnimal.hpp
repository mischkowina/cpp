/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:05:08 by smischni          #+#    #+#             */
/*   Updated: 2023/01/20 18:23:56 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"

class AAnimal {
	protected:
		std::string	type;

	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual	~AAnimal(void);

		AAnimal	&operator=(AAnimal const &rhs);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif
