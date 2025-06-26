/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:15 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/26 15:50:45 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

void	megaphone(std::string str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
	std::cout << str;
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; av[i]; i++)
		megaphone(av[i]);
	std::cout << std::endl;
	return (0);
}


