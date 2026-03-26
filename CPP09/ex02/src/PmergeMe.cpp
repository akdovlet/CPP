/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:04:50 by akdovlet          #+#    #+#             */
/*   Updated: 2026/03/25 15:03:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GroupIterator.hpp"
#include "PmergeMe.hpp"

int comp_count = 0;

void	merge_sort(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return;
	bool hasStray = vec.size() % 2 ? true : false;
	std::vector<int>::iterator last = hasStray ? vec.end() - 1 : vec.end();
	std::vector<int> main;
	std::vector<int> pend;
	for (std::vector<int>::iterator it = vec.begin(); it != last; it += 2)
	{
		if (*it > *(it + 1))
		{
			comp_count++;		
			main.push_back(*it);
		}
		else
		{
			comp_count++;		
			pend.push_back(*(it + 1));
		}
	}
	merge_sort(main);
	for (std::vector<int>::iterator it = main.begin(); it != main.end(); it++)
		std::cout << "main: " << *it << std::endl;
}
