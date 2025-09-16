/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:22:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/16 13:29:21 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char* AForm::NotSignedFormException::what() const throw()
{
	return ("Form not signed");
}

AForm::AForm() : _name("Anon"), _signed(false), _gradeSign(1), _gradeExec(1)
{
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeExec), _gradeExec(other._gradeSign)
{	
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeExec < 1 || _gradeSign < 1)
		throw GradeTooHighException();
	if (_gradeExec > 150 || _gradeSign > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool				AForm::getSigned() const
{
	return (_signed);
}

int					AForm::getGradeSign() const
{
	return (_gradeSign);
}

int					AForm::getGradeExec() const
{
	return (_gradeExec);
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os	<< form.getName() 
		<< ", signed: " 
		<< form.getSigned() 
		<< ", required grade to sign: " 
		<< form.getGradeSign()
		<< ", required grade to execute: "
		<< form.getGradeExec() << std::endl;
	return (os);
}

void	AForm::beSigned(Bureaucrat& br)
{
	if (br.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw GradeTooLowException();
}
