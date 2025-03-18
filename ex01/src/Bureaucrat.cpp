/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:14 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 21:13:33 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : _name("Anonymous"), _grade(0)
{
	
}


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if(grade > 150)
	{
		throw(GradeTooLowException());
	}
	else if(grade < 1)
	{
		throw(GradeTooHighException());
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
{
	*this = toCopy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	if(this != &toCopy)
	{
		_grade = toCopy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &toDisplay)
{
	os << toDisplay.getName() << ", bureaucrate grade " << toDisplay.getGrade() << endl;
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return GRADE_TOO_HIGH_EXCEPTION;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return GRADE_TOO_LOW_EXCEPTION;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		cout << _name << " signed " << form.getName() << endl;
	}
	catch(const std::exception& e)
	{
		cout << _name << " couldn't sign " << form.getName()
		<< " because of the following reason : "
		<< e.what() << endl;
	}
	
}
