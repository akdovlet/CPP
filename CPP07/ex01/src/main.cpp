/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:58:23 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/25 19:22:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <string.h>

int main()
{
	char *str = strdup("Check This Out!");
	
	iter<char, char (const char &) >(str, 16, print<char>);

	std::cout << str << std::endl;
}
