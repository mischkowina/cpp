/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:46:22 by smischni          #+#    #+#             */
/*   Updated: 2023/01/12 13:11:48 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"

class Fixed {
	private:
		int					value;
		static const int	fract_bits = 8;

	public:
		Fixed(void);
		~Fixed(void);
		
		Fixed(Fixed f);
		Fixed	&operator=(Fixed rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
