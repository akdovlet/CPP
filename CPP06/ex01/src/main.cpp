/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:24:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/24 17:36:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	uintptr_t	addr;
	Data		*ptrAddr = new Data("Hello World!");

	std::cout << "original pointer addr: " << ptrAddr << std::endl;
	std::cout << "original ptrAddr string: " << ptrAddr->getValue() << std::endl;
	
	addr = Serializer::serialize(ptrAddr);
	ptrAddr = Serializer::deserialize(addr);
	
	std::cout << "serialized address: "  << std::setw(5) << std::hex << "0x" << addr << std::endl;
	std::cout << "deserialized address: "<< std::setw(15)   << ptrAddr << std::endl;
	std::cout << "deserialized data string: " << ptrAddr->getValue() << std::endl;
	
	delete ptrAddr;
	return (0);
}
