/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:59:52 by marvin            #+#    #+#             */
/*   Updated: 2025/11/14 14:59:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){	
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	void (other);
	return (*this);
}

const char *ScalarConverter::WrongInputException::what()
{
	return ("Invalid input");
}

static int parsing(std::string str)
{
	bool dot = false;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>str[i]) && !(str[i] == '+' || str[i] == '-' || str[i] == '.' || str[i] == 'f'))
			return 1;
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			return 1;
		if (str[i] == '.')
		{
			if (!dot)
				dot = true;
			else
				return 1;	
		}
		if (str[i] == 'f' && i != str.size() - 1)
			return 1;
	}
	return 0;
}

static t_type checkType(std::string str)
{
	if (str.empty())
		return (INVALID);	
	else if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (SPECIAL);
	else if (str.size() == 1 && !std::isdigit(static_cast<unsigned char>str[0]))
		return (NORMAL);	
	else if (parsing(str))
		return (INVALID);
	return (NORMAL);
}

static void convertSpecial(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	};
}

static void printConversion(std::string str)
{
	double value;

	if str.size() == 1 && !std::isdigit(static_cast<unsigned char>str[0])
	{
		if 
	}
}

void ScalarConverter::convert(std::string str)
{
	t_type type = checkType(str);
	switch(type)
	{
		case 0:
			throw ScalarConvertion::what();
			break;
		case 1:
			printConversion(str);
			break;
		case 2:
			convertSpecial(str);
			break;
	}

}
