/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:48:41 by smischni          #+#    #+#             */
/*   Updated: 2023/01/31 16:57:31 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cerr << "Error: Programm needs exactly one argument." << std::endl;
		return (1);
	}
	try {
		std::string	str(argv[1]);
		ScalarConverter::convert(str);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
