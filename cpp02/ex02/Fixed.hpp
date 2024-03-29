/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:46:22 by smischni          #+#    #+#             */
/*   Updated: 2023/01/13 17:40:38 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
		Fixed(Fixed const &src);
		Fixed(int const i);
		Fixed(float const f);
		~Fixed(void);
		
		Fixed	&operator=(Fixed const &rhs);
		
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		bool	operator<(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator>(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		Fixed	&operator++();//pre-increment
		Fixed	&operator--();//pre-decrement
		Fixed	operator++(int);//post-increment
		Fixed	operator--(int);//post-decrement

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
