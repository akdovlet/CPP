/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:59:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/07 20:24:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

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
	<< "And you better pay me the respect that I gave your father or we're gonna have a problem" << std::endl;
}

void	Harl::complain(const std::string& level)
{
	size_t	i;
	funcPtr arr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	const std::string	msg[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (level == msg[i])
		{
			(this->*(arr[i]))();
			return ;
		}
		i++;
	}
}
