/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:43:52 by marvin            #+#    #+#             */
/*   Updated: 2025/11/17 15:43:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(Serializer &){}
Serializer &Serializer::operator=(Serializer &){
	return (*this);
}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}