/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:08:29 by smischni          #+#    #+#             */
/*   Updated: 2023/02/11 19:37:46 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# ifndef MESSAGE
#  define MESSAGE 0
# endif

# define DEFAULT "\033[0m"
# define YELLOW "\033[33m"
# define PINK "\033[35m"
# define BLUE "\033[36m"


# include <exception>
# include <algorithm>
# include <iostream>
# include <vector>
# include <numeric>
# include <cstdlib>
# include <ctime>

class Span {
	private:
		unsigned int		maximum;
		std::vector<int>	nbrs;
		bool				isSorted;

		Span();

	public:
		Span(unsigned int N);
		Span(Span const &rhs);
		~Span();

		Span	&operator=(Span const &rhs);
		
		void	addNumber(int i);
		void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void	fillRandom();
		int		shortestSpan();
		int		longestSpan();
		void	printSpan() const;

		class NotEnoughNumbers : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class NotEnoughSpace : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

#endif
