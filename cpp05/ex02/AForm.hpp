/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:36 by smischni          #+#    #+#             */
/*   Updated: 2023/01/27 16:43:55 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	name;
		bool				isSigned;
		int const			signGrade;
		int const			execGrade;

	public:
		AForm();
		AForm(std::string name);
		AForm(int signGrade, int execGrade);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const &rhs);
		virtual ~AForm();

		AForm	&operator=(AForm const &rhs);

		int					checkGrade(int grade) const;
		std::string const	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void			beSigned(Bureaucrat const &signer);
		void			execute(Bureaucrat const &executor) const;
		virtual void	execution() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		}; 

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
