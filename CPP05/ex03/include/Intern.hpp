/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:02:43 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/16 21:43:49 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	/* data */
public:
	Intern();
	Intern(const Intern& other);
	Intern&	operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(const std::string& name, const std::string target);
};

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

AForm*	Intern::makeForm(const std::string& name, const std::string target)
{
	std::string	arr[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	funcPtr		fArr[4] = {&RobotomyRequestForm(target),}
	AForm		*ptr = NULL;
	for (int i = 0; arr[i] != name; i++)
	{
	}
	if (name == "robotomy request")
		return new RobotomyRequestForm(target);
	if (name == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	if (name == "presidential pardon")
		return new PresidentialPardonForm(target);
	std::cout << "Error: form does not exist." << std::endl;	
	return (NULL);
}

#endif
