/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:55:05 by smischni          #+#    #+#             */
/*   Updated: 2023/02/11 13:05:04 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>
# include <iostream>
# include <iterator>

# define DEFAULT "\033[0m"
# define YELLOW "\033[33m"

class NotFoundException : public std::exception {
	public:
		virtual const char	*what() const throw() {return ("No match for parameter found.");};
};

template <typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator i = find(container.begin(), container.end(), n);
	if (i != container.end())
		return (i);
	else
		throw NotFoundException();
}

#endif
