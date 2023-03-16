/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:53:41 by smischni          #+#    #+#             */
/*   Updated: 2023/03/16 12:53:49 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << RED "Error: " DEFAULT << "Not enough arguments." << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		if (!isValidInput(argv[i]))
		{
			std::cout << RED "Error: " DEFAULT << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
	}
	
	PmergeMe	sort(argc, argv);
}