/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:04:01 by smischni          #+#    #+#             */
/*   Updated: 2023/02/02 16:08:25 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

# ifndef MESSAGE
#  define MESSAGE 0
# endif

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define BLUE "\033[36m"

class Data {
	private:
		std::string	my_darkest_secret;

	public:
		Data();
		Data(Data const &rhs);
		~Data();
		
		Data	&operator=(Data const &rhs);

		void		setMyDarkestSecret(std::string secret);
		std::string	getMyDarkestSecret() const;
};

#endif
