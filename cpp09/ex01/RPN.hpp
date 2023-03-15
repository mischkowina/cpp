/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:54 by smischni          #+#    #+#             */
/*   Updated: 2023/03/15 12:56:04 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define DEFAULT "\033[0m"
# define RED "\033[31m"

# include <iostream>
# include <string>
# include <stack>

class RPN {
	private:
		int				_result;
		std::stack<int>	_calculation;

	public:
		RPN();
		RPN(std::string input);
		RPN(RPN const &rhs);
		~RPN();
		RPN	&operator=(RPN const &rhs);

		int	getResult() const;
};

#endif
