/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:54:50 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/24 15:49:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base*	generate(void)
{
	switch (std::rand() % 3)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default:
		return (NULL);
	}
}

void	identify(Base* p)
{
	if (!p)
	{
		std::cout << "NULL pointer" << std::endl;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is of type A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "pointer is of type B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "pointer is of type C" << std::endl;
}

void	identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "reference is of type A" << std::endl;
	if (dynamic_cast<B*>(&p))
		std::cout << "reference is of type B" << std::endl;
	if (dynamic_cast<C*>(&p))
		std::cout << "reference is of type C" << std::endl;
}
