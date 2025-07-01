/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:25:43 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/01 19:21:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

int main()
{
	char	time_string[] = "yyyymmdd_hhmmss";
	time_t		local_t;
	struct tm	*curr_t;

	time(&local_t);
	curr_t = localtime(&local_t);
	std::strftime(time_string,18,"[%G%m%d_%H%M%S]", curr_t);
	std::cout << time_string << std::endl;
}
