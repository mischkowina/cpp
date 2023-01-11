/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:12:38 by smischni          #+#    #+#             */
/*   Updated: 2023/01/11 13:23:46 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		std::cout << "Arguments: filename, string1, string2" << std::endl;
		return (1);
	}

	std::string		filename(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string	line;
	size_t		pos;
	
	ifs.open(filename, std::ifstream::in);
	ofs.open(filename + ".replace", std::ofstream::out | std::ofstream::trunc);
	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "Error: Could not open file." << std::endl;
		return (1);
	}
	
	while (getline(ifs, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1);
		}
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
