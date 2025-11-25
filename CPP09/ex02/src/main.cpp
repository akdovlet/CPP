/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:46:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/11/25 17:13:10 by akdovlet         ###   ########.fr       */
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
	vec.push_back(10);
	
	std::vector<int>::iterator it = vec.begin();
	
	// GroupIterator<std::vector<int>::iterator> groupIt(it, 1);

	// swap_ranges<std::vector<int>::iterator >(groupIt, ++groupIt);

	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << std::endl;
	std::vector<int>::iterator end = vec.end();
	
	std::cout << "size: " << end - it << std::endl;
	
	return (0);
}

template<typename Iterator>
void	merge_insertion_sort(Iterator first, Iterator last)
{
	int size = last - first;
	if (size < 2)
		return ;
	
	bool hasStray = size % 2 != 0;
	Iterator end = hasStray ? std::prev(last) : last;
	for (Iterator it = first; it != end; it += 2)
	{
		
	}
}
