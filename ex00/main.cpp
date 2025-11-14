/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:47:51 by marvin            #+#    #+#             */
/*   Updated: 2025/11/14 15:47:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <typeinfo>
#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, char** argv)
{
	if (argc =! 2)
	{
		std::cout << "Please put only 1 input to convert!" << std::endl;;
		return 1;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}