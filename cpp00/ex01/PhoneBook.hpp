/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:59:20 by smischni          #+#    #+#             */
/*   Updated: 2023/01/09 14:34:14 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib> //for atoi
# include "Contact.hpp"

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define BLUE "\033[36m"

class PhoneBook {
	private:
		Contact	contacts[8];
		int		cur_idx;
	
	public:
		void	set_idx(int idx);
		void	add_contact(void);
		void	display_phonebook(void);
};

#endif
