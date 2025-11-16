/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:59:55 by marvin            #+#    #+#             */
/*   Updated: 2025/11/14 14:59:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cctype>

enum t_type
{
	INVALID = 0;
	CHAR = 1;
	NUMBER = 2;
	SPECIAL = 3;
}

class ScalarConverter
{
	public:
			void convert(std::string str);
			class WrongInputException : public std::exception
			{
				public:
					virtual const char *what() const throw();
			}
	private:
			ScalarConverter();
			~ScalarConverter();
			ScalarConverter(const ScalarConverter &copy);
			ScalarConverter& operator=(const ScalarConverter &other);
}

#endif