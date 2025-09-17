/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:49:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/17 19:31:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "=== Parametrized Constructor Grade Too Low Test ===" << std::endl;
	try
	{
		Bureaucrat Janice("Janice", 2234444);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n=== Parametrized Constructor Grade Too High Test ===" << std::endl;
	try
	{
		Bureaucrat Chrissy("Chrissy", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n=== Increment Grade Past Range Test ===" << std::endl;
	try
	{
		Bureaucrat Kim("Kim", 1);
		Kim.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== << Operator Overload Test ===" << std::endl;
	{
		Bureaucrat Donny("Donny", 1);
		try
		{
			Donny.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << Donny;
		}
		std::cout << "Outside of try-catch block: " << Donny << std::endl;
	}

	// std::cout << "\n=== Form Sign Test" << std::endl;
	// {
	// 	Bureaucrat Joe("Joe", 2);
	// 	AForm		presidentialPardon("Presidential Pardon Form", 1, 1);
	// 	try
	// 	{
	// 		Joe.signForm(presidentialPardon);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	Bureaucrat Donny("Donny", 1);
	// 	try
	// 	{
	// 		Donny.signForm(presidentialPardon);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
		
	// }
	std::cout << "\n=== << Khabib Shrubbery Test ===" << std::endl;
	{
		Bureaucrat Khabib("Khabib", 145);
		ShrubberyCreationForm Shrub("small");

		Khabib.signForm(Shrub);
		Khabib.executeForm(Shrub);
	}
	std::cout << "\n=== << Robotomy Test ===" << std::endl;
	{
		Bureaucrat Bender("Bender", 1);
		RobotomyRequestForm robotForm("");

		Bender.signForm(robotForm);
		Bender.executeForm(robotForm);
	}
	
	std::cout << "\n=== << Presidential Pardon Test ===" << std::endl;
	{
		Bureaucrat	Jay("Jay", 1);
		AForm		*form = new PresidentialPardonForm("Snowden");
		
		try
		{
			Jay.signForm(*form);
			Jay.executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		Bureaucrat Jojo("Jojo", 25);
		try
		{
			Jojo.signForm(*form);
			Jojo.executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		delete form;
	}

	std::cout << "\nIntern Test" << std::endl;
	{
		Intern 	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat	zorg("Zorg", 1);
		Bureaucrat	midManager("manager", 73);
		midManager.signForm(*rrf); // can't sign
		midManager.incrementGrade();
		midManager.signForm(*rrf); // can sign
		zorg.signForm(*rrf);
		zorg.executeForm(*rrf);
		midManager.executeForm(*rrf);

		delete rrf;
	}

		std::cout << "\nIntern Test" << std::endl;
	{
		Intern 	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << "Pointer value: " << rrf << std::endl;
		Bureaucrat	Flanders("Flanders", 1);
		Flanders.executeForm(*rrf);
	}

}
