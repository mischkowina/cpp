/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:04:13 by smischni          #+#    #+#             */
/*   Updated: 2023/01/07 16:20:09 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

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

		void	display_contact(void);
		void	set_idx(int idx);
		void	set_first(void);
		void	set_last(void);
		void	set_nick(void);
		void	set_phone(void);
		void	set_secret(void);
};

#endif
