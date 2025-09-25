/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:18:09 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/25 10:35:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac > 1)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "./convert [value]" << std::endl;
}
