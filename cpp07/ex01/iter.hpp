/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:54:54 by smischni          #+#    #+#             */
/*   Updated: 2023/02/09 16:18:10 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef ITER_HPP
 # define ITER_HPP

# define DEFAULT "\033[0m"
# define YELLOW "\033[33m"

# include <cstdio>

template <typename T>
void	iter(T *arr, size_t len, void (*f)(T &t))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	plusplus(T &t)
{
	t++;
}

 #endif
 