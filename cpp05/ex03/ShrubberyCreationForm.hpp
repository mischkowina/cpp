/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:59:58 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 16:52:26 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		
		void	execution() const;

		class FailedOpeningOutfileException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

#endif
