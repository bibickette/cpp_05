/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:01:12 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 00:40:34 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

using std::cout;
using std::endl;

Intern::Intern()
{}

Intern::Intern(const Intern &toCopy)
{
	*this = toCopy;
}

Intern &Intern::operator=(const Intern &toCopy)
{
	if(this != &toCopy)
	{

	}
	return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeShrub(std::string target)
{
	return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobot(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm *Intern::makePresident(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string tab[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*(Intern::*functionTab[])(std::string) = {&Intern::makeShrub, &Intern::makeRobot, &Intern::makePresident};

	for(size_t i = 0; i < 3; i++)
	{
		if(formName == tab[i])
		{
			cout << "Intern creates " << tab[i] << endl;
			return ((this->*functionTab[i])(formTarget));
		}
	}
	throw(FormCreationException());
}

const char *Intern::FormCreationException::what() const throw()
{
	return FORM_CREATION_EXCEPTION;
}