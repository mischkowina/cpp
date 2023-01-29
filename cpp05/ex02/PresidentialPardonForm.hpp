/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:55:36 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 16:53:25 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &rhs);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		
		void	execution() const;
};

#endif
