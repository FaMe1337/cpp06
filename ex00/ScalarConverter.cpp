/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.valuer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:59:52 by marvin            #+#    #+#             */
/*   Updated: 2025/11/14 14:59:52 by marvin           ###   ########.valuer       */
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

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return (*this);
}

const char *ScalarConverter::WrongInputException::what() const throw()
{
	return ("Invalid input");
}

static void printSpecial(std::string str)
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

static void printChar(char c)
{
	std::cout << "char : ";
	if (!isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c <<"\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) <<".0" << std::endl;
}

static int parsing(std::string str)
{
	bool dot = false;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])) && !(str[i] == '+' || str[i] == '-' || str[i] == '.' || str[i] == 'f'))
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

static int countDecimals(std::string str)
{
	size_t found = str.find('.');
	if (found != std::string::npos)
	{
		int decimals = str.size() - found - 1;
		if (decimals > 6)
			return 6;
		return decimals;	
	}
	return 0;
}

static void printDouble(double value, int decimals)
{
	if (value >= CHAR_MIN && value <= CHAR_MAX)
	{
		std::cout << "char : ";
		if (isprint(static_cast<char>(value)))
			std::cout << "\'" << static_cast<unsigned char>(value) <<"\'" << std::endl;
		else
		std::cout << "Non displayable" << std::endl;	
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (value >= INT_MIN && value <= INT_MAX)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float : ";
	if (!decimals)
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(decimals) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double : ";
	if (!decimals)
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << std::fixed << std::setprecision(decimals) << value << std::endl;
}

static t_type checkType(std::string str)
{
	if (str.empty())
		return (INVALID);	
	else if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (SPECIAL);
	else if (str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return (CHAR);	
	else if (parsing(str))
		return (INVALID);
	return (NUMBER);
}

void ScalarConverter::convert(const std::string &str)
{
	t_type type = checkType(str);
	double value;
	switch(type)
	{
		case 0:
			throw ScalarConverter::WrongInputException();
		case 1:
		{
			char c = str[0];
			value = static_cast<double>(c);
			printChar(value);
			return;
		}
		case 2:
		{
			std::string toParse = str;
			if (toParse[toParse.size() - 1] == 'f')
				toParse = toParse.substr(0, toParse.size() - 1);
			int decimals = countDecimals(toParse);	
			value = std::strtod(toParse.c_str(), NULL);
			printDouble(value, decimals);
			return;
		}	
		case 3:
			printSpecial(str);
			return;
	}
}
