/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:52:53 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/08 16:02:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"

int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream 	outfile;
	std::string		buffer;
	const char		*filename;

	
	if (ac != 4)
	{
		std::cerr	<< "Error: Invalid arguments\n"
					<< "<filename> <toFind> <replace>" << std::endl;
		return (1);
	}
	const std::string		toFind(av[2]);
	const std::string		replace(av[3]);
	filename = av[1];
	if (!open_files(filename, infile, outfile))
		return (1);
	while (getline(infile, buffer))
	{
		search_and_replace(toFind, replace, buffer);
		outfile << buffer;
		if (!infile.eof() && !infile.fail())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
}
