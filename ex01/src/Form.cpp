/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:31:00 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:39:51 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::cout;
using std::endl;

Form::Form() : _name("Anonymous"), _isSigned(false), _gradeForSign(0), _gradeForExec(0)
{
	cout << YELLOW << "Default Form constructor called" << RESET << endl;
}
Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeForSign(gradeSign), _gradeForExec(gradeExec)
{
	cout << YELLOW << "Form Parameter constructor called" << RESET << endl;
	if(gradeSign < 1 || gradeExec < 1)
	{
		throw(Form::GradeTooHighException());
	}
	else if(gradeSign > 150 || gradeExec > 150)
	{
		throw(Form::GradeTooLowException());		
	}
}

Form::Form(const Form &toCopy) : _name(toCopy._name), _isSigned(toCopy._isSigned), _gradeForSign(toCopy._gradeForSign), _gradeForExec(toCopy._gradeForExec)
{
	cout << YELLOW << "Form Copy constructor called" << RESET << endl;
	*this = toCopy;
}

Form &Form::operator=(const Form &toCopy)
{
	cout << YELLOW << "Affectation Form constructor called" << RESET << endl;
	if(this != &toCopy)
	{
		_isSigned = toCopy._isSigned;
	}
	return *this;
}

Form::~Form()
{
	cout << YELLOW << "Form Destructor called" << RESET << endl;
}

std::string Form::getName() const
{
	return _name;	
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

void Form::beSigned(Bureaucrat &guy)
{
	if(guy.getGrade() <= _gradeForSign && _isSigned)
	{
		throw(AlreadySignedException());
		
	}
	else if (guy.getGrade() > _gradeForSign)
	{
		throw(TooLowToSignException());
	}
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return GRADE_FORM_TOO_HIGH_EXCEPTION;
}
const char *Form::GradeTooLowException::what() const throw()
{
	return GRADE_FORM_TOO_LOW_EXCEPTION;
}
const char *Form::AlreadySignedException::what() const throw()
{
	return ALREADY_SIGNED_EXCEPTION;
}

const char *Form::TooLowToSignException::what() const throw()
{
	return GRADE_TOO_LOW_SIGN_EXCEPTION;
}

std::ostream &operator<<(std::ostream &os, const Form &toDisplay)
{
	os << toDisplay.getName() << " is a" ;
	if(toDisplay.getIsSigned())
	{
		os << " signed form" << endl;
	}
	else
	{
		os << "n unsigned form" << endl;
	}
	return os;
}
