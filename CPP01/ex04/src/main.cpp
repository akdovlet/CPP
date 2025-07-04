/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:52:53 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/04 20:50:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"

int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream 	outfile;
	std::string		buffer;
	std::size_t		pos;

	if (ac != 4)
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (infile.fail())
	{
		std::cerr << "Error: Failed opening infile" << std::endl;
		return (1);
	}
	outfile.open(std::string(av[1]) + ".replace");
	if (outfile.fail())
	{
		std::cerr << "Error: Failed opening outfile" << std::endl;
		infile.close();
		return (1);
	}
	while (infile.eof())
	{
		infile >> buffer;
		pos = buffer.find(av[2]);
		if (pos == std::string::npos)
			continue ;
		
	}
}
