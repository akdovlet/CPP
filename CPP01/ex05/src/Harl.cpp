/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:59:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/10 23:53:17 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void	Harl::debug(void)
{
	std::cout << "Thought I told you to back the fuck off Beansie" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Oh you think this is funny? That guy might never walk again." << std::endl;
	std::cout << "And for what? Cause he didn't duke you enough? Cause he didn't visit you in the can?" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "When's the last time you visited anyone in the can Richie?\n"
	<< "When's the last time you gave a fuck about anybody but Richie Aprile?" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Here's a rule you might remember: I'm the motherfucking fucking one who calls the shots\n"
	<< "And you better pay me the respect that I gave your problem or we're gonna have a problem" << std::endl;
}

void	Harl::complain(std::string level)
{
	size_t	i;
	funcPtr arr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	msg[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (level == msg[i])
			break ;
		i++;
	}
	if (i < 4)
		(this->*(arr[i]))();
}
