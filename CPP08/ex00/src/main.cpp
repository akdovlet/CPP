/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:21:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/27 19:09:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <deque>

int main()
{
	std::cout << "=== Vector test ===" << std::endl;
	{
		std::vector<int> v1(10);
		for (int i = 0; i < 10; i++)
			v1[i] = i;
	
		std::vector<int>::iterator it = easyfind(v1, 2345);
		if (it != v1.end())
			std::cout << "Found number: " << *it << std::endl;
		else
			std::cout << "Not found" << std::endl;
	
		it = easyfind(v1, 5);
		if (it != v1.end())
			std::cout << "Found number: " << *it << std::endl;
		else
			std::cout << "Not found" << std::endl;		
	}
	std::cout << "\n=== List test ===" << std::endl; 
	{
		std::list<int> lst;
		for (int i = 0; i < 10; i++)
			lst.push_back(i);
		
		std::list<int>::iterator it = easyfind(lst, 2345);
		if (it != lst.end())
			std::cout << "Found number: " << *it << std::endl;
		else
			std::cout << "Not found" << std::endl;
	
		it = easyfind(lst, 5);
		if (it != lst.end())
			std::cout << "Found number: " << *it << std::endl;
		else
			std::cout << "Not found" << std::endl;	
	}

	std::cout << "\n=== Deque test ===" << std::endl; 
	{
		std::deque<int> dq;
		for (int i = 0; i < 10; i++)
			dq.push_back(i);
		
		std::deque<int>::iterator it = easyfind(dq, 2345);
		if (it != dq.end())
			std::cout << "Found number: " << *it << std::endl;
		else
			std::cout << "Not found" << std::endl;
	
		it = easyfind(dq, 5);
		if (it != dq.end())
			std::cout << "Found number: " << *it << std::endl;
		else
			std::cout << "Not found" << std::endl;	
	}
	return (0);	
}
