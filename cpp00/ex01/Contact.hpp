/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:04:13 by smischni          #+#    #+#             */
/*   Updated: 2023/01/06 18:10:42 by smischni         ###   ########.fr       */
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

		void		set_first(std::string);
		std::string	get_first();
};

#endif
