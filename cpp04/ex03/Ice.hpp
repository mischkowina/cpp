/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:46:00 by smischni          #+#    #+#             */
/*   Updated: 2023/01/22 16:49:32 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(Ice const &rhs);
		~Ice(void);

		Ice	&operator=(Ice const &rhs);

		AMateria	*clone(void) const;
};

#endif
