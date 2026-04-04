/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:43:48 by marvin            #+#    #+#             */
/*   Updated: 2025/11/17 15:43:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data original;
	original.name = "Zé";
	original.value = 42;

	std::cout << "name from original is: " << original.name << std::endl;
	std::cout << "value from original is: " << original.value << std::endl;
	std::cout << "original memory adress is : " << &original << std::endl;
	uintptr_t ptr = Serializer::serialize(&original);

	Data *data2;
	data2 = Serializer::deserialize(ptr);
	std::cout << "name from data2 is: " << data2->name << std::endl;
	std::cout << "value from data2 is: " << data2->value << std::endl;
	std::cout << "data2 memory adress is : " << data2 << std::endl;
}