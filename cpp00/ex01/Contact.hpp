/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:04:13 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 17:36:17 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define BLUE "\033[36m"

class Contact {
	private:
		int			index;
		std::string	first;
		std::string	last;
		std::string	nick;
		std::string	phone;
		std::string	secret;

	public:
		Contact(void);//constructor
		~Contact(void);//desctructor

		void		display_contact(void);
		void		set_idx(int idx);
		void		set_first(void);
		std::string	get_first(void);
		void		set_last(void);
		std::string	get_last(void);
		void		set_nick(void);
		std::string	get_nick(void);
		void		set_phone(void);
		void		set_secret(void);
};

#endif
