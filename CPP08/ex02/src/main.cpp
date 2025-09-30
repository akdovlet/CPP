/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/30 18:45:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mt;
	
	mt.push(13);
	mt.push(10);
	mt.push(20);
	mt.push(40);

	MutantStack<int> m2 = mt;
	for (int i = 0; i < 4; i++)
	{
		std::cout << m2.top() << std::endl;
		m2.pop();
	}
	return (0);
}
