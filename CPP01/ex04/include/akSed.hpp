/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   akSed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:53:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/08 23:11:19 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <fstream>

void	search_and_replace(const std::string &toFind, const std::string &replace, std::string &buf);
bool	open_files(char **av, std::ifstream &infile, std::ofstream &outfile);
