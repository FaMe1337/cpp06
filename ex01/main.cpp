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
	Data data;
	data.name = "Zé";
	data.value = 42;

	std::cout << "name from data is: " << data.name << std::endl;
	std::cout << "value from data is: " << data.value << std::endl;
	std::cout << "data memory adress is : " << &data << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);

	Data *data2;
	data2 = Serializer::deserialize(ptr);
	std::cout << "name from data2 is: " << data2->name << std::endl;
	std::cout << "value from data2 is: " << data2->value << std::endl;
	std::cout << "data2 memory adress is : " << &data << std::endl;
}