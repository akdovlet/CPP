/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:12:27 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/02 17:07:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac > 1 && std::string(av[1]) == "rand")
	{
		std::cout << "=== random 20k values test === " << std::endl;
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
		std::cout << "=== positive values test === " << std::endl;
		{
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
		std::cout << "\n=== Positive and negative values test === " << std::endl;
		{
			Span sp(10);

			sp.addNumber(-1);
			sp.addNumber(3);
			sp.addNumber(-41);
			sp.addNumber(332);
			sp.addNumber(58);
			sp.addNumber(12);
			sp.addNumber(89);
			sp.addNumber(-22);
			sp.addNumber(24);
			sp.addNumber(-8);

			std::cout << "Size: " << sp.getSize() << std::endl;
			std::cout << "Count: " << sp.getCount() << std::endl;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		
		std::cout << "\n=== Exceptions Test ===" << std::endl;
		{
			Span	sp(2);
			
			sp.addNumber(1);
			sp.addNumber(1);
			try
			{
				sp.addNumber(1);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}

			Span	sp2(2);

			try
			{
				sp2.shortestSpan();
				sp2.longestSpan();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		std::cout << "\n=== Provided main test ===" << std::endl;
		{
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}

		std::cout << "\n=== Insert range test ===" << std::endl;
		{
			Span sp(4);
			std::vector<int> range;
			range.push_back(1);
			range.push_back(2);
			range.push_back(3);
			range.push_back(4);
			range.push_back(5);
			range.push_back(6);
			range.push_back(7);
			range.push_back(8);
			range.push_back(9); 
			range.push_back(10);
			
			sp.insert(sp.end() - 2, range.begin() + 4, range.end());

			for (std::vector<int>::iterator it = sp.begin(); it != sp.end(); it++)
				std::cout << *it << std::endl;
		}
	}
	return (0);
}
