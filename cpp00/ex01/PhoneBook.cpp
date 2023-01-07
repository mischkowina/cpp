/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:02:46 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 16:21:49 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::set_idx(int idx)
{
	cur_idx = idx;
}

void	PhoneBook::add_contact(void)
{
	std::cout << "Okay, let's get it over with." << std::endl;
	contacts[cur_idx].set_idx(cur_idx);
	contacts[cur_idx].set_first();
	contacts[cur_idx].set_last();
	contacts[cur_idx].set_nick();
	contacts[cur_idx].set_phone();
	contacts[cur_idx].set_secret();
	if (cur_idx == 7)
		cur_idx = 0;
	else
		cur_idx++;
}

