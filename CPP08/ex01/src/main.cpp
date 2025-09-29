/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:12:27 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/29 13:14:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac > 1 && std::string(av[1]) == "rand")
	{
		std::cout << "random 20k values test" << std::endl;
		srand(time(NULL)^clock());
		
		Span sp(20000);
	
		for (int i = 0; i < 20000; i++)
		{
			int randN = rand();
			sp.addNumber(randN);
			// std::cout << i << ": " << randN << std::endl;
		}
		std::cout << "Size: " << sp.getSize() << std::endl;
		std::cout << "Count: " << sp.getCount() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;		
	}
	else
	{
		std::cout << "positive values test" << std::endl;
		Span sp(10);
		sp.addNumber(10);
		sp.addNumber(5);
		sp.addNumber(30);
		sp.addNumber(1);
		sp.addNumber(8);
		sp.addNumber(15);
		sp.addNumber(42);
		sp.addNumber(22);
		sp.addNumber(12);
		sp.addNumber(88);
		std::cout << "Size: " << sp.getSize() << std::endl;
		std::cout << "Count: " << sp.getCount() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;	
	}
	return (0);
}
