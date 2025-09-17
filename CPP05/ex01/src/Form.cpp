/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:22:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/17 18:39:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

Form::Form() : _name("Anon"), _signed(false), _gradeSign(1), _gradeExec(1)
{
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeExec), _gradeExec(other._gradeSign)
{	
}

Form::Form(const std::string &name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeExec < 1 || _gradeSign < 1)
		throw GradeTooHighException();
	if (_gradeExec > 150 || _gradeSign > 150)
		throw GradeTooLowException();
}

void	Form::swap(Form& left, Form& right)
{
	using std::swap;
	swap(left._signed, right._signed);
}

Form& Form::operator=(Form other)
{
	swap(*this, other);
	return (*this);
}

Form::~Form()
{
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

int					Form::getGradeSign() const
{
	return (_gradeSign);
}

int					Form::getGradeExec() const
{
	return (_gradeExec);
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os	<< form.getName() 
		<< ", signed: " 
		<< form.getSigned() 
		<< ", required grade to sign: " 
		<< form.getGradeSign()
		<< ", required grade to execute: "
		<< form.getGradeExec() << ".";
	return (os);
}

void	Form::beSigned(Bureaucrat& br)
{
	if (br.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw GradeTooLowException();
}
