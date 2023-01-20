/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:56:13 by smischni          #+#    #+#             */
/*   Updated: 2023/01/20 18:28:40 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain	*brain;
	
	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		Dog	&operator=(Dog const &rhs);

		void		makeSound(void) const;
		void		setIdea(std::string newIdea, unsigned int index);
		std::string	getIdea(unsigned int index) const;
		Brain		&getBrain(void) const;
};

#endif
