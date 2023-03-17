/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:37:53 by smischni          #+#    #+#             */
/*   Updated: 2023/03/17 11:33:00 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define DEFAULT "\033[0m"
# define RED "\033[31m"

# include <iostream>
# include <string>
# include <deque>
# include <list>
# include <limits>
# include <utility>
# include <algorithm>
# include <sys/time.h>
# include <stdexcept>

class PmergeMe {
	private:
		std::deque<int>	_deque;
		std::list<int>	_list;
		double			_dequeTime;
		double			_listTime;

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &rhs);

		void	sortDeque(int argc, char **argv);
		void	sortList(int argc, char **argv);
};

bool			isValidInput(char *str);
struct timeval	getTime();


#endif
