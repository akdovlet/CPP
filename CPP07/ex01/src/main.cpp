/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:58:23 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/26 14:33:19 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <string.h>

void	doStuff(int *arr, const int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
}

int main()
{
	char str[] = "Check This Out!";

	std::string	msg[2] = {"Hey,", "What's up?"};
	
	std::cout << "=== char * Test ===" << std::endl;
	iter<char, char (const char &)>(str, strlen(str), print<char>);
	
	std::cout << "\n=== std::string Test ===" << std::endl;
	iter(msg, 2, printArr<const std::string>);

	std::cout << "\n=== const char[] test ===" << std::endl;
	iter("Sup nerd", 9, printArr<char>);
	// iter("Sup nerd", 9, tolower);
	
	std::cout << "\n=== Array of int Test ===" << std::endl;
	const int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print<int>);
}
