/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:49:09 by smischni          #+#    #+#             */
/*   Updated: 2023/01/11 14:27:37 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	karen;

	std::cout << std::endl << "Experience the for stages of Harl's rage:" << std::endl;
	
	std::cout << std::endl << "****** DEBUG ******" << std::endl;
	karen.complain("debug");

	std::cout << std::endl << "****** INFO ******" << std::endl;
	karen.complain("info");

	std::cout << std::endl << "****** WARNING ******" << std::endl;
	karen.complain("warning");

	std::cout << std::endl << "****** ERROR ******" << std::endl;
	karen.complain("error");
	std::cout << std::endl;
	return (0);
}
