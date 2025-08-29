/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:21:13 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 14:38:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(FragTrap other);
    ~FragTrap();

	void	swap(FragTrap& other);

	void	highFivesGuys(void);
};

#endif
