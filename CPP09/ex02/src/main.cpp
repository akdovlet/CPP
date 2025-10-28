/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:46:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/28 19:59:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "GroupIterator.hpp"

int main()
{
	std::vector<int> vec;
	
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	
	std::vector<int>::iterator it = vec.begin();
	
	GroupIterator<std::vector<int>::iterator> groupIt(it, 1);

	swap_ranges<std::vector<int>::iterator >(groupIt, ++groupIt);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	
	
	return (0);
}
