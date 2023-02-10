/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:49:22 by smischni          #+#    #+#             */
/*   Updated: 2023/02/10 17:18:14 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <cstdio>

# define DEFAULT "\033[0m"
# define YELLOW "\033[33m"

template <typename T>
class Array {
	private:
		std::size_t	arraySize;
		T			*array;
		
	public:
		Array<T>() : array(new T[0]), arraySize(0) {};
		Array<T>(unsigned int n) : array(new T[n]), arraySize(n) {};
		Array<T>(Array<T> const &obj) : array(new T[obj.size()]), arraySize(obj.size())
		{
			for (int i = 0; i < this->arraySize; i++)
				this->array[i] = obj.array[i];
		}
		~Array<T>() {delete[] this->array;};

		Array<T>	&operator=(Array<T> const &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->arraySize = rhs.arraySize();
			if (this->array != NULL)
				delete[] this->array;
			this->array = new T[this->arraySize];
			for (int i = 0; i < this->arraySize; i++)
				this->array[i] = rhs.array[i];
			return (*this);
		}
		
		T	&operator[](std::size_t n)
		{
			if (n < 0 || n >= this->arraySize)
				throw std::exception();
			return (array[n]);
		}

		std::size_t	size() const {return (this->arraySize);};
};

#endif
