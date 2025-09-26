/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:35:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/26 18:06:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> arr(10);
	Array<std::string> splitter(2);

	splitter[0] = "Praise be";
	splitter[1] = "The Lord";

	arr[0] = 1;
	arr[3] = 7;
	arr[4] = 1787;
	arr[6] = 45;
	arr[7] = 47;
	Array<int>	cpy(arr);

	for (std::size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;

	std::cout << "=== cpy test ===" << std::endl;
	for (std::size_t i = 0; i < cpy.size(); i++)
		std::cout << cpy[i] << std::endl;
		

	for (std::size_t i = 0; i < splitter.size(); i++)
		std::cout << splitter[i] << std::endl;

	try
	{
		std::cout << splitter[4] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
