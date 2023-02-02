/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:33:48 by smischni          #+#    #+#             */
/*   Updated: 2023/02/02 16:15:38 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

# ifndef MESSAGE
#  define MESSAGE 0
# endif

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define BLUE "\033[36m"
# define YELLOW "\033[33m"

# define M

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const &rhs);
		~Serializer();

		Serializer	&operator=(Serializer const &rhs);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data* 		deserialize(uintptr_t raw);
};

#endif
