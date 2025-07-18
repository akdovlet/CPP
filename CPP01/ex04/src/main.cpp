/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:52:53 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/08 23:10:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"

int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream 	outfile;
	std::string		buffer;
	
	if (ac != 4)
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		return (1);
	}
	if (!open_files(av, infile, outfile))
		return (1);
	while (getline(infile, buffer))
	{
		search_and_replace(av[2], av[3], buffer);
		outfile << buffer << "\n";
	}
}
