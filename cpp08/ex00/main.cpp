/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:15:49 by smischni          #+#    #+#             */
/*   Updated: 2023/02/11 13:06:44 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <list>
#include <queue>
#include <stack>

void	printInt(int value)
{
	std::cout << value << std::endl;
}

int	main()
{
	std::cout << YELLOW "**** TEST 1: LIST ****" DEFAULT << std::endl;
	std::list<int>	l;
	l.push_back(42);
	l.push_back(23);
	l.push_back(12);
	l.push_back(10);
	std::cout << "LIST CONTENT:" << std::endl;
	for_each(l.begin(), l.end(), printInt);
	std::cout << "TRYING TO FIND 42:" << std::endl;
	try
	{
		std::cout << "Index of first occurence of 42 is: " << std::distance(l.begin(), easyfind(l, 42)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << YELLOW "**** TEST 2: DEQUE ****" DEFAULT << std::endl;
	std::deque<int>	q;
	q.push_back(34);
	q.push_back(4343);
	q.push_back(42343);
	q.push_back(42);
	std::cout << "DEQUE CONTENT:" << std::endl;
	for_each(q.begin(), q.end(), printInt);
	std::cout << "TRYING TO FIND 42:" << std::endl;
	try
	{
		std::cout << "Index of first occurence of 42 is: " << std::distance(q.begin(), easyfind(q, 42)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << YELLOW "**** TEST 3: VECTOR ****" DEFAULT << std::endl;
	std::vector<int>	v;
	v.push_back(32);
	v.push_back(32);
	v.push_back(32);
	std::cout << "VECTOR CONTENT:" << std::endl;
	for_each(v.begin(), v.end(), printInt);
	std::cout << "TRYING TO FIND 42:" << std::endl;
	try
	{
		std::cout << "Index of first occurence of 42 is: " << std::distance(v.begin(), easyfind(v, 42)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}