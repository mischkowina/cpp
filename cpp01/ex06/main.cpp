/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:49:09 by smischni          #+#    #+#             */
/*   Updated: 2023/01/11 18:10:38 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	getIdx(std::string level);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Only one argument allowed." << std::endl;
		return (1);
	}
	
	Harl		karen;
	std::string	level(argv[1]);
	int			idx;

	idx = getIdx(level);
	switch (idx)
	{
		case 0:
		{
			karen.complain("debug");
			break;
		}
		case 1:
		{
			karen.complain("info");
			break;
		}
		case 2:
		{
			karen.complain("warning");
			break;
		}
		case 3:
		{
			karen.complain("error");
			break;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	
	return (0);
}

int	getIdx(std::string level)
{
	std::string	type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (type[i] == level)
			return (i);
	}
	return (-1);
}
