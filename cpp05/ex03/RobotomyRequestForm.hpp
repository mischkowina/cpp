/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:53 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 16:52:08 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &rhs);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		
		void	execution() const;
};

#endif
