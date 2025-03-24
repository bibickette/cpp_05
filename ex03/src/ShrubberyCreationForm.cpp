/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:57:36 by phwang            #+#    #+#             */
/*   Updated: 2025/03/24 15:05:40 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("NoName", 145, 137), _target("NoTarget")
{
	cout << GREEN << "Default ShrubberyCreationForm constructor called" << RESET << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string formName) : AForm("ShrubberyCreationForm", 145, 137),  _target(formName)
{
	cout << GREEN << "ShrubberyCreationForm Parameter constructor called" << RESET << endl;

}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy): AForm(toCopy.getName(), 145, 137), _target(toCopy._target)
{
	cout << GREEN << "ShrubberyCreationForm Copy constructor called" << RESET << endl;
	*this = toCopy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopy)
{
	cout << GREEN << "Affectation operator ShrubberyCreationForm constructor called" << RESET << endl;
	if(this != &toCopy)
	{

	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << GREEN << "ShrubberyCreationForm Destructor called" << RESET << endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(!this->getIsSigned())
	{
		throw(NotSignedException());
	}
	if(executor.getGrade() > this->getGrade(EXEC_FLAG))
	{
		throw(TooLowToExecException());
	}
	
	std::string filename = _target;
	std::ofstream outputFile((filename += "_shrubbery").c_str());
	if (!outputFile.is_open())
	{
		throw(FileCreationException());
	}

	outputFile << "       _-_" << endl;
	outputFile << "    /~~   ~~\\" << endl;
	outputFile << " /~~         ~~\\" << endl;
	outputFile << "{               }" << endl;
	outputFile << " \\  _-     -_  /" << endl;
	outputFile << "   ~  \\\\ //  ~" << endl;
	outputFile << "_- -   | | _- _" << endl;
	outputFile << "  _ -  | |   -_" << endl;
	outputFile << "      // \\\\" << endl;
	
	outputFile.close();
}

const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return CREATION_FILE_FAIL_EXCEPTION;
}

	  