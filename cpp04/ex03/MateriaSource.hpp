/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:27 by smischni          #+#    #+#             */
/*   Updated: 2023/01/23 15:22:06 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*materias[4];
	
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &rhs);
		~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &rhs);
		
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

#endif
