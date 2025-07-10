/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:59:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/10 22:39:56 by akdovlet         ###   ########.fr       */
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
	std::map<std::string, funcPtr> indexMap;

	indexMap["DEBUG"] = &Harl::debug;
	indexMap["INFO"] = &Harl::info;
	indexMap["WARNING"] = &Harl::warning;
	indexMap["ERROR"] = &Harl::error;
	
	std::map<std::string, funcPtr>::iterator it = indexMap.find(level);
	if (it != indexMap.end())
		(this->*(it->second))();
}
