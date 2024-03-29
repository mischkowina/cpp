/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:36 by smischni          #+#    #+#             */
/*   Updated: 2023/01/27 17:36:36 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	name;
		bool				isSigned;
		int const			signGrade;
		int const			execGrade;

		Form	&operator=(Form const &rhs);

	public:
		Form();
		Form(std::string name);
		Form(int signGrade, int execGrade);
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const &rhs);
		~Form();

		int					checkGrade(int grade) const;
		std::string const	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void	beSigned(Bureaucrat const &signer);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		}; 

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		}; 
		
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
