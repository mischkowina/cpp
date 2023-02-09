/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:13:19 by smischni          #+#    #+#             */
/*   Updated: 2023/02/09 14:57:27 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define DEFAULT "\033[0m"
# define YELLOW "\033[33m"

template <typename T>
void	swap(T &x, T &y)
{
	T	tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T	min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template <typename T>
T	max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

#endif
