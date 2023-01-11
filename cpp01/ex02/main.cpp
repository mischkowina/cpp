/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:42:44 by smischni          #+#    #+#             */
/*   Updated: 2023/01/11 18:18:06 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// void	change_by_ref(std::string &stringREF);

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "MEMORY ADDRESS" << std::endl;
	std::cout << "string:\t\t" << &string << std::endl;
	std::cout << "stringPTR:\t" << stringPTR << std::endl;
	std::cout << "stringREF:\t" << &stringREF << std::endl << std::endl;

	std::cout << "VALUE" << std::endl;
	std::cout << "string:\t\t" << string << std::endl;
	std::cout << "stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "stringREF:\t" << stringREF << std::endl << std::endl;

	// change_by_ref(stringREF);

	// std::cout << "VALUE" << std::endl;
	// std::cout << "string:\t\t" << string << std::endl;
	// std::cout << "stringPTR:\t" << *stringPTR << std::endl;
	// std::cout << "stringREF:\t" << stringREF << std::endl;
	
	return (0);
}

// void	change_by_ref(std::string &stringREF)
// {
// 	stringREF = "Saskia";
// }
