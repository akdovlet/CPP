/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:05:24 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/11 19:52:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*_brain;

	void	swap(Cat& lha, Cat& rha);
public:
	Cat();
	Cat(const Cat& cat);
	Cat&	operator=(Cat other);
	~Cat();
	
	void	makeSound() const;

	void				putIdea(const std::string& str, const int index);
	const std::string	getIdea(const int index) const;
};

#endif
