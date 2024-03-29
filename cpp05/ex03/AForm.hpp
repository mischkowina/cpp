/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:01:36 by smischni          #+#    #+#             */
/*   Updated: 2023/01/29 16:53:01 by smischni         ###   ########.fr       */
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
		std::string const	target;

		AForm	&operator=(AForm const &rhs);

	public:
		AForm();
		AForm(std::string name);
		AForm(int signGrade, int execGrade);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(std::string name, int signGrade, int execGrade, std::string target);
		AForm(AForm const &rhs);
		virtual ~AForm();

		int					checkGrade(int grade) const;
		std::string const	getName() const;
		bool				getIsSigned() const;
		void				setIsSigned(bool status);
		int					getSignGrade() const;
		int					getExecGrade() const;
		std::string const	getTarget() const;

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
