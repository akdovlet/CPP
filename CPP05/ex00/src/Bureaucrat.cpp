/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:43:53 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/17 16:21:51 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anon"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::swap(Bureaucrat& left, Bureaucrat& right)
{
	using std::swap;
	swap(left._grade, right._grade);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat other)
{
	swap(*this, other);
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& br)
{
	os << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
	return (os);
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}
