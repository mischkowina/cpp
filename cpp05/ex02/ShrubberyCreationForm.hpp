/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:59:58 by smischni          #+#    #+#             */
/*   Updated: 2023/01/27 17:57:07 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		
	
	public:
		ShrubberyCreationForm();//make private again
		ShrubberyCreationForm(ShrubberyCreationForm const &rhs);//make private again
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);//make private
		
		void	execution() const;

		class FailedOpeningOutfileException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

#endif
