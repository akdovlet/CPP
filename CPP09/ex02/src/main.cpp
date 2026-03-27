/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:46:52 by akdovlet          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "GroupIterator.hpp"
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int comp_count = 0;

void	parse_values(char *av, std::deque<int>& deq, std::vector<int>& vec)
{
	std::stringstream	sstr;
	int					n = 0;
	sstr << av;
	sstr >> n;
	if (sstr.fail())
		throw std::runtime_error("Error: bad input");
	if (n < 0)
		throw std::runtime_error("Error: negative value");
	deq.push_back(n);
	vec.push_back(n);
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (1);
	std::clock_t start;
	std::clock_t end;
	std::deque<int> deq;
	std::vector<int> vec;

	start = clock();
	for (int i = 1; i < ac; i++)
		parse_values(av[i], deq, vec);
	end = clock();
	std::cout << std::fixed << std::setprecision(3) << "Time to parse data: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms" << std::endl;

	std::cout << "Before: ";
	for	(std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << (next(it) != deq.end() ? " " :  "\n");
	
	comp_count = 0;
	std::clock_t start_vec = std::clock();
	merge_insertion_sort(vec.begin(), vec.end());
	std::clock_t end_vec = std::clock();
	
	comp_count = 0;
	std::clock_t start_deq = std::clock();
	merge_insertion_sort(deq.begin(), deq.end());
	std::clock_t end_deq = std::clock();
	
	std::cout << "After: ";
	for	(std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << (next(it) != deq.end() ? " " :  "\n");

	std::cout << std::fixed << std::setprecision(3) << "Time to sort data using vector: " << 1000.0 * (end_vec - start_vec) / CLOCKS_PER_SEC << "ms using " << comp_count << " comparisons" << std::endl;
	std::cout << std::fixed << std::setprecision(3) << "Time to sort data using deque: " << 1000.0 * (end_deq - start_deq) / CLOCKS_PER_SEC << "ms using " << comp_count << " comparisons" << std::endl;

	return (0);
}
