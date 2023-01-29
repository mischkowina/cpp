/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:57:36 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 17:40:16 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		Intern(Intern const &rhs);
		Intern	&operator=(Intern const &rhs);
	
	public:
		Intern();
		~Intern();
		
		AForm	*makeForm(std::string name, std::string target) const;
};

#endif
