/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:12:38 by smischni          #+#    #+#             */
/*   Updated: 2023/01/10 16:27:25 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		std::cout << "Arguments: filename, string1, string2" << std::endl;
		return (1);
	}

	std::string	filename(argv[1]);

	
	
	return (0);
}
