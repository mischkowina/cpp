/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:09 by smischni          #+#    #+#             */
/*   Updated: 2023/01/20 18:28:30 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain	*brain;
	
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat	&operator=(Cat const &rhs);

		void		makeSound(void) const;
		void		setIdea(std::string newIdea, unsigned int index);
		std::string	getIdea(unsigned int index) const;
		Brain		&getBrain(void) const;
};

#endif
