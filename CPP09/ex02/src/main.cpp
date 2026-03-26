/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:46:52 by akdovlet          #+#    #+#             */
/*   Updated: 2026/03/26 21:23:49 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "GroupIterator.hpp"
#include "PmergeMe.hpp"

int main()
{
	std::vector<int> vec;
	
	vec.push_back(10);
	vec.push_back(2);
	vec.push_back(34);
	vec.push_back(4);
	vec.push_back(22);
	vec.push_back(7);
	vec.push_back(12);
	
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator end = vec.end();
	

	merge_insertion_sort<typename std::vector<int>::iterator>(it, end);
	for (it = vec.begin(); it != end; it++)
		std::cout << "value: " << *it << std::endl;
	
	return (0);
}
