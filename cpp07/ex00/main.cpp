/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:09:21 by smischni          #+#    #+#             */
/*   Updated: 2023/02/09 15:02:23 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <string>

int	main()
{
	std::cout << YELLOW "**** SUBJECT TESTS ****" DEFAULT << std::endl;
	int a = 2;
	int b = 3;
	
	::swap(a,b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a,b) = " << ::min(a,b) << std::endl;
	std::cout << "max(a,b) = " << ::max(a,b) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c,d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c,d) = " << ::min(c,d) << std::endl;
	std::cout << "max(c,d) = " << ::max(c,d) << std::endl;

	std::cout << YELLOW "**** ANOTHER TEST ****" DEFAULT << std::endl;
	float y = 42.4242;
	float x = 0.2121;
	::swap(y,x);
	std::cout << "y = " << y << ", x = " << x << std::endl;
	std::cout << "min(y,x) = " << ::min(y,x) << std::endl;
	std::cout << "max(y,x) = " << ::max(y,x) << std::endl;
	return (0);
}
