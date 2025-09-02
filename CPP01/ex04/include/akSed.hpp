/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   akSed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:53:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/01 15:50:26 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AKSED_HPP
#define AKSED_HPP

#include <string>
#include <iostream>
#include <fstream>

void	search_and_replace(const std::string &toFind, const std::string &replace, std::string &buf);
bool	open_files(const char *filename, std::ifstream &infile, std::ofstream &outfile);

#endif
