/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:59:20 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 15:41:55 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int		cur_idx;
	
	public:
		void	set_idx(int idx);
		void	add_contact(void);
};

#endif
