/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:39:36 by smischni          #+#    #+#             */
/*   Updated: 2023/03/17 17:16:55 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << "Before:\t";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	struct timeval	startTime = getTime();
	this->sortDeque(argc, argv);
	struct timeval	dequeTime = getTime();
	_dequeTime = (dequeTime.tv_sec - startTime.tv_sec) * 1000000 + (dequeTime.tv_usec - startTime.tv_usec);

	startTime = getTime();
	this->sortList(argc, argv);
	struct timeval	listTime = getTime();
	_listTime = (listTime.tv_sec - startTime.tv_sec) * 1000000 + (listTime.tv_usec - startTime.tv_usec);
	
	if (!std::is_sorted(_deque.begin(), _deque.end()) || !std::is_sorted(_list.begin(), _list.end()))
		throw std::logic_error("Algorithm failed sorting.");
	
	std::cout << "After:\t";
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of\t" << argc - 1 << " elemenets with std::deque:\t" << _dequeTime << " us" << std::endl;
	std::cout << "Time to process a range of\t" << argc - 1 << " elemenets with std::list:\t" << _listTime << " us" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &rhs)
{
	if (this != &rhs)
		*this = rhs;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_deque = rhs._deque;
		this->_list = rhs._list;
		this->_dequeTime = rhs._dequeTime;
		this->_listTime = rhs._listTime;
	}
	return *this;
}

void	PmergeMe::sortDeque(int argc, char **argv)
{
	//put input in deque
	for (int i = 1; i < argc; i++)
	{
		_deque.push_back(atoi(argv[i]));
	}

	//make pairs and put them in another deque, first value is always the bigger
	std::deque<std::pair<int, int> >	pair_deque;
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		int	&first = *it;
		std::pair<int, int> pair;
		if (it + 1 == _deque.end())
			pair = std::make_pair(-1, first);
		else if (*(++it) > first)
			pair = std::make_pair(*it, first);
		else
			pair = std::make_pair(first, *it);	
		pair_deque.push_back(pair);
	}

	//clear original deque, all elements were copied into pairs
	_deque.clear();
	
	//insertion sort the pair_deque
	std::deque<std::pair<int, int> >::iterator it1 = pair_deque.begin();
	while (it1 != pair_deque.end())
	{
		std::deque<std::pair<int, int> >::iterator first = it1++;
		if (it1 == pair_deque.end())
			break;
		std::deque<std::pair<int, int> >::iterator second = it1;
		while (second->first < first->first)
		{
			std::swap(*second, *first);
			if (first == pair_deque.begin())
				break;
			first--;
			second--;
		}
	}
	
	//insert the sorted bigger values in the original deque and create a second deque with the smaller values
	it1 = pair_deque.begin();
	std::deque<int> smallerValues;
	while (it1 != pair_deque.end())
	{
		if (it1->first != -1)
			_deque.push_back(it1->first);
		smallerValues.push_back(it1->second);
		it1++;
	}

	//insertion sort the smaller values into the original deque
	while (!smallerValues.empty())
	{
		if (smallerValues.front() < _deque.front())
			_deque.push_front(smallerValues.front());
		else 
		{
			std::deque<int>::iterator it = _deque.begin();
			it++;
			while (smallerValues.front() > *it && it != _deque.end())
				it++;
			if (it == _deque.end())
				_deque.push_back(smallerValues.front());
			else
				_deque.insert(it, smallerValues.front());
		}
		smallerValues.pop_front();
	}
}

void	PmergeMe::sortList(int argc, char **argv)
{
	//put input in list
	for (int i = 1; i < argc; i++)
	{
		_list.push_back(atoi(argv[i]));
	}
	
	//make pairs and put them in another list, first value is always the bigger
	std::list<std::pair<int, int> >	pair_list;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		int	&first = *it;
		std::pair<int, int> pair;
		if (++it == _list.end())
		{
			pair = std::make_pair(-1, first);
			it--;
		}	
		else if (*it > first)
			pair = std::make_pair(*it, first);
		else
			pair = std::make_pair(first, *it);
		pair_list.push_back(pair);
	}

	//clear original list, all elements were copied into pairs
	_list.clear();
	
	//insertion sort the pair_list
	std::list<std::pair<int, int> >::iterator it1 = pair_list.begin();
	while (it1 != pair_list.end())
	{
		std::list<std::pair<int, int> >::iterator first = it1++;
		if (it1 == pair_list.end())
			break;
		std::list<std::pair<int, int> >::iterator second = it1;
		while (second->first < first->first)
		{
			std::swap(*second, *first);
			if (first == pair_list.begin())
				break;
			first--;
			second--;
		}
	}
	
	//insert the sorted bigger values in the original list and create a second list with the smaller values
	it1 = pair_list.begin();
	std::list<int> smallerValues;
	while (it1 != pair_list.end())
	{
		if (it1->first != -1)
			_list.push_back(it1->first);
		smallerValues.push_back(it1->second);
		it1++;
	}
	
	//insertion sort the smaller values into the original list
	while (!smallerValues.empty())
	{
		if (smallerValues.front() < _list.front())
			_list.push_front(smallerValues.front());
		else 
		{
			std::list<int>::iterator it = _list.begin();
			it++;
			while (smallerValues.front() > *it && it != _list.end())
				it++;
			if (it == _list.end())
				_list.push_back(smallerValues.front());
			else
				_list.insert(it, smallerValues.front());
		}
		smallerValues.pop_front();
	}
}

bool	isValidInput(char *str)
{
	std::string	nbr(str);

	size_t pos = nbr.find_first_not_of("0123456789", 0);
	if (pos != std::string::npos)
		return false;

	if (atol(str) > std::numeric_limits<int>::max())
		return false;
	
	return true;
}

struct timeval	getTime()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		throw std::logic_error("gettimeofday() failed.");
	
	return time;
}