/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:45:42 by smischni          #+#    #+#             */
/*   Updated: 2023/02/11 21:25:46 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << YELLOW "**** SUBJECT TEST WITH LIST (REFERENCE OUTPUT) ****" DEFAULT << std::endl;
		std::list<int>	mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() <<std::endl;
		mstack.pop_back();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while(it != ite) 
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << YELLOW "**** SUBJECT TEST WITH MUTANT STACK ****" DEFAULT << std::endl;
		MutantStack<int>	mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() <<std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while(it != ite) 
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::cout << YELLOW "**** TRY REVERSE ITERATORS ****" DEFAULT << std::endl;
	
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		while(rit != rite) 
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	return (0);
}