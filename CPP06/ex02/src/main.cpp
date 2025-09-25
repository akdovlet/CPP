/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:58:18 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/25 14:23:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	
	std::cout << "=== Class A test ===" << std::endl;
	{
		Base* basePtr = new A();
		Base& baseRef = *basePtr;
	
		identify(basePtr);
		identify(baseRef);

		delete basePtr;
	}

	std::cout << "\n=== Class B test ===" << std::endl;
	{
		Base* basePtr = new B();
		Base& baseRef = *basePtr;
	
		identify(basePtr);
		identify(baseRef);

		delete basePtr;
	}

	std::cout << "\n=== Class C test ===" << std::endl;
	{
		Base* basePtr = new C();
		Base& baseRef = *basePtr;
	
		identify(basePtr);
		identify(baseRef);

		delete basePtr;
	}
	
	std::cout << "\n=== Random class generator test ===" << std::endl;
	{
		Base* basePtr = generate();
		Base& baseRef = *basePtr;
	
		identify(basePtr);
		identify(baseRef);
	
		delete basePtr;
	}

		std::cout << "\n=== NULL test ===" << std::endl;
	{
		Base* basePtr = NULL;
		Base& baseRef = *basePtr;
	
		identify(basePtr);
		identify(baseRef);
	}

	std::cout << "\n=== C test ===" << std::endl;
	{
		C* cPtr = new C();
		Base& cRef = *cPtr;
	
		identify(cPtr);
		identify(cRef);
	}
}
