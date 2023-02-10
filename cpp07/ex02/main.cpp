/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:51:29 by smischni          #+#    #+#             */
/*   Updated: 2023/02/10 17:26:13 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int>		nbrs(5);
	
	std::cout << YELLOW "**** ARRAY OF 5 INTS AFTER INITIALIZATION ****" DEFAULT << std::endl;
	for (int i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << std::endl;
	std::cout << "size: " << nbrs.size() << std::endl;
	
	std::cout << YELLOW "**** SET TO DIFFERENT VALUES ****" DEFAULT << std::endl;
	for (int i = 0; i < nbrs.size(); i++)
		nbrs[i] = i * 10;
	for (int i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << std::endl;
	
	std::cout << YELLOW "**** CREATE A COPY & DISPLAY IT ****" DEFAULT << std::endl;
	Array<int>	copy(nbrs);

	for (int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << std::endl;

	std::cout << YELLOW "**** CHANGE THE ORIGINAL AND DISPLAY BOTH ****" DEFAULT << std::endl;
	nbrs[0] = 100;
	std::cout << "ORIGINAL:" << std::endl;
	for (int i = 0; i < nbrs.size(); i++)
		std::cout << nbrs[i] << std::endl;
	std::cout << "COPY:" << std::endl;
	for (int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << std::endl;
	
	std::cout << YELLOW "**** TRY TO ACCESS INDEX OUT OF BOUNDS ****" DEFAULT << std::endl;
	try
	{
		std::cout << nbrs[15] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << nbrs[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << YELLOW "**** EMPTY ARRAY (DEFAULT CONSTRUCTOR) ****" DEFAULT << std::endl;
	Array<int>	test;
	
	for (int i = 0; i < test.size(); i++)
		std::cout << test[i] << std::endl;
	std::cout << "size: " << test.size() << std::endl;
	return(0);
}
