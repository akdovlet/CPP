/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:24:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/24 13:43:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	Data	data("Hello World!");

	uintptr_t	addr;
	Data		*ptrAddr;

	addr = Serializer::serialize(&data);
	ptrAddr = Serializer::deserialize(addr);
	
	std::cout << "original pointer addr: " << &data << std::endl;
	std::cout << "serialized address: "  << std::setw(5) << std::hex << "0x" << addr << std::endl;
	std::cout << "deserialized address: "<< std::setw(15)   << ptrAddr << std::endl;
	return (0);
}
