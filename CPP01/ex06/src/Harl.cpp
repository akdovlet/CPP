/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:59:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/07 21:28:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(){
}

Harl::~Harl(){
}

void	Harl::debug(void) const
{
	std::cout << "Thought I told you to back the fuck off Beansie" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "Oh you think this is funny? That guy might never walk again.\n"
	<< "And for what? Cause he didn't duke you enough? Cause he didn't visit you in the can?" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "When's the last time you visited anyone in the can Richie?\n"
	<< "When's the last time you gave a fuck about anybody but Richie Aprile?" << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "Here's a rule you might remember: I'm the motherfucking fucking one who calls the shots\n"
	<< "And you better pay me the respect that I gave your brother or we're gonna have a problem" << std::endl;
}

void	Harl::complain(const std::string& level)
{
	size_t		i;
	funcPtr 	arr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*(arr[i]))();
			return ;
		}
		i++;
	}
}

void	harlFilter(const std::string& level)
{
	size_t		i;
	Harl		harl;

	i = 0;
	while (i < 4)
	{
		if (level == Harl::levels[i])
			break ;
		i++;
	}
	switch (i)
	{
	case (0):
		std::cout << "[ DEBUG ]\n";
		harl.complain("DEBUG");
		std::cout << std::endl;
		__attribute__((fallthrough));
	case(1):
		std::cout << "[ INFO ]\n";
		harl.complain("INFO");
		std::cout << std::endl;
		__attribute__((fallthrough));
	case(2):
		std::cout << "[ WARNING ]\n";
		harl.complain("WARNING");
		std::cout << std::endl;
		__attribute__((fallthrough));
	case(3):
		std::cout << "[ ERROR ]\n";
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
