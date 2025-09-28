/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:12:27 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/28 19:51:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int main()
{
	srand(time(NULL)^clock());
	
	Span sp(10);

	for (int i = 0; i < 10; i++)
	{
		int randN = rand() % 100;
		sp.addNumber(randN);
		std::cout << i << ": " << randN << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	
	return (0);
}
