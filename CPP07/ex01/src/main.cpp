/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:58:23 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/27 13:33:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>
#include <string.h>

int main()
{
	char str[] = "Check This Out!";

	std::string	msg[2] = {"Hey,", "What's up?"};

	std::cout << "=== char * Test ===" << std::endl;
	iter(str, strlen(str), print<char>);
	
	std::cout << "\n=== const char[] test ===" << std::endl;
	iter("Sup nerd", 9, print<char>);
	// iter("Sup nerd", 9, tolower);

	std::cout << "\n=== std::string array Test ===" << std::endl;
	iter(msg, 2, print<const std::string>);

	std::cout << "\n=== Array of int Test ===" << std::endl;
	const int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print<int>);

	std::cout << "\n=== Float array test ===" << std::endl;
	
	float	farr[] = {344.5f, 12.001f, 1001.1f};
	iter(farr, 3, print<float>);

	std::cout << "\n=== NULL pointer test ===" << std::endl;
	int	*iPtr = NULL;
	iter(iPtr, 10, print<int>);	
}
