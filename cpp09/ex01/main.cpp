/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:30 by smischni          #+#    #+#             */
/*   Updated: 2023/03/15 15:22:40 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED "ERROR: " DEFAULT << "Needs exactly one string as input parameter." << std::endl;
		return 1;
	}

	std::string	input(argv[1]);
	try
	{
		RPN			calculation(input);
		std::cout << calculation.getResult() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED "ERROR: " DEFAULT << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}