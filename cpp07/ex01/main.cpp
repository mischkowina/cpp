/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:08:46 by smischni          #+#    #+#             */
/*   Updated: 2023/02/09 21:45:39 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int	main()
{
	{
		int	i[5] = {0, 1, 2, 3, 4};
		
		std::cout << YELLOW "**** int array before ****" DEFAULT << std::endl;
		for (int a = 0; a < 5; a++)
			std::cout << "i[" << a << "]: " << i[a] << std::endl;
		
		::iter(i, 5, ::plusplus<int>);
		
		std::cout << YELLOW "**** int array after ****" DEFAULT << std::endl;
		for (int a = 0; a < 5; a++)
			std::cout << "i[" << a << "]: " << i[a] << std::endl;
		std::cout << std::endl;
	}
	{
		float	i[5] = {0.05, 1.05, 2.05, 3.05, 4.05};
		
		std::cout << YELLOW "**** float array before ****" DEFAULT << std::endl;
		for (int a = 0; a < 5; a++)
			std::cout << "i[" << a << "]: " << i[a] << std::endl;
		
		::iter(i, 5, ::plusplus<float>);
		
		std::cout << YELLOW "**** float array after ****" DEFAULT << std::endl;
		for (int a = 0; a < 5; a++)
			std::cout << "i[" << a << "]: " << i[a] << std::endl;
		std::cout << std::endl;
	}
	{
		char	i[5] = {'A', 'B', 'C', 'D', 'E'};
		
		std::cout << YELLOW "**** char array before ****" DEFAULT << std::endl;
		for (int a = 0; a < 5; a++)
			std::cout << "i[" << a << "]: " << i[a] << std::endl;
		
		::iter(i, 5, ::plusplus<char>);
		
		std::cout << YELLOW "**** char array after ****" DEFAULT << std::endl;
		for (int a = 0; a < 5; a++)
			std::cout << "i[" << a << "]: " << i[a] << std::endl;
	}
	return (0);
}