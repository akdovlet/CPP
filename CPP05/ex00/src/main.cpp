/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:49:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/17 16:13:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Parametrized Constructor Grade Too Low Test ===" << std::endl;
	try
	{
		Bureaucrat Janice("Janice", 2234444);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n=== Parametrized Constructor Grade Too High Test ===" << std::endl;
	try
	{
		Bureaucrat Chrissy("Chrissy", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n=== Increment Grade Past Range Test ===" << std::endl;
	try
	{
		Bureaucrat Kim("Kim", 1);
		Kim.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== Decrement Grade Past Range Test ===" << std::endl;
	try
	{
		Bureaucrat Mandem("Mandem", 150);
		Mandem.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== << Operator Overload Test ===" << std::endl;
	{
		Bureaucrat Donny("Donny", 1);
		try
		{
			Donny.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << Donny;
		}
		std::cout << "Outside of try-catch block: " << Donny << std::endl;
	}
}
