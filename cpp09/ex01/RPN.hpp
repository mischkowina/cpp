/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:54 by smischni          #+#    #+#             */
/*   Updated: 2023/03/15 14:41:53 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define DEFAULT "\033[0m"
# define RED "\033[31m"

# include <iostream>
# include <string>
# include <stack>
# include <exception>
# include <stdexcept>

class RPN {
	private:
		std::stack<int>	_calculation;

	public:
		RPN();
		RPN(std::string input);
		RPN(RPN const &rhs);
		~RPN();
		RPN	&operator=(RPN const &rhs);

		int		getResult() const;
		void	addToCalculation(std::string element);

		bool	isValidInt(std::string str);
		bool	isOperator(std::string str);
};



#endif
