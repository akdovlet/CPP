/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/01 20:26:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "randomAccessIterator.hpp"
#include <iostream>
#include <list>
#include <string>

#include <vector>

int main()
{
	std::cout << "=== Mutan stack output ===" << std::endl;
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack); 
	}

	std::cout << "\n=== std list output ===" << std::endl;
	{
		std::list<int> lst;
		
		lst.push_back(5);
		lst.push_back(17);
		
		std::cout << lst.back() << std::endl;
		
		lst.pop_back();
		
		std::cout << lst.size() << std::endl;
		
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		
		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(lst); 
	}

		std::cout << "\n=== const iterator output ===" << std::endl;
	{
		MutantStack<int, std::vector<int> > mvector;

		mvector.push(1);
		mvector.push(2);
		mvector.push(3);
		mvector.push(4);
		mvector.push(5);
		
		for (MutantStack<int>::const_iterator rit = mvector.cbegin(); rit != mvector.cend(); rit++)
			std::cout << *rit << std::endl;
	}
	
		std::cout << "\n=== Reverse iterator output ===" << std::endl;
	{
		MutantStack<int, std::vector<int> > mstack;
		
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();

		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::vector<int> > s(mstack); 
	}

	std::cout << "\n=== Const reverse iterator output ===" << std::endl;
	{
		MutantStack<int, std::vector<int> > mvector;

		mvector.push(1);
		mvector.push(2);
		mvector.push(3);
		mvector.push(4);
		mvector.push(5);
		
		for (MutantStack<int>::const_reverse_iterator rit = mvector.crbegin(); rit != mvector.crend(); rit++)
			std::cout << *rit << std::endl;
	}
	return 0;
}
