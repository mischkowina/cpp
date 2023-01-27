/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:33:18 by smischni          #+#    #+#             */
/*   Updated: 2023/01/27 16:51:01 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

# ifndef MESSAGE
#  define MESSAGE 0
# endif

# define DEFAULT "\033[0m"
# define PINK "\033[35m"
# define BLUE "\033[36m"
# define YELLOW "\033[33m"

class AForm;

class Bureaucrat {
	private:
		std::string const	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &rhs);
		~Bureaucrat();

		Bureaucrat	&operator=(Bureaucrat const &rhs);

		std::string const	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm &form) const;
		void				executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		}; 

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		}; 
		
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
