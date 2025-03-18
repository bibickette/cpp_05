/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:14 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 18:16:32 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	os << toDisplay.getName() << ", bureaucrate grade " << toDisplay.getGrade() << ".\n";
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high, has to be maximal 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low, has to be minimal 150";
}