/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:56:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/17 16:42:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

AForm*	robotomyFactory(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	shrubberyFactory(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	presidentialFactory(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string target)
{
	std::string	arr[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	funcPtr		fArr[3] = {robotomyFactory, shrubberyFactory, presidentialFactory};

	for (int i = 0; i < 3; i++)
	{
		if (name == arr[i])
		{
			std::cout << "Intern creates " << arr[i] << " form" << std::endl;
			return (*(fArr[i]))(target);
		}
	}
	std::cout << name << " form does not exist" << std::endl;
	return (NULL);
}
