/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:01:36 by smischni          #+#    #+#             */
/*   Updated: 2023/02/11 21:02:18 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define DEFAULT "\033[0m"
# define YELLOW "\033[33m"

# include <stack>
# include <deque>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	private:
		MutantStack(MutantStack const &rhs) {*this = rhs;}
		MutantStack	&operator=(MutantStack const &rhs)
		{
			(void)rhs;
			return (*this);
		}
	
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack() {}
		~MutantStack() {}
		
		iterator				begin() {return (this->c.begin());}
		iterator				end() {return (this->c.end());}
		reverse_iterator		rbegin() {return (this->c.rbegin());}
		reverse_iterator		rend() {return (this->c.rend());}
		const_iterator			cbegin() const {return (this->c.cbegin());}
		const_iterator			cend() const {return (this->c.cend());}
		const_reverse_iterator	crbegin() const {return (this->c.crbegin());}
		const_reverse_iterator	crend() const {return (this->c.crend());}
};

#endif
