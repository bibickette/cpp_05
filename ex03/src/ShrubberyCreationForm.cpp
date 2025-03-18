/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:57:36 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 23:43:48 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("NoName", 145, 137), _target("NoTarget")
{}
ShrubberyCreationForm::ShrubberyCreationForm(std::string formName) : AForm("ShrubberyCreationForm", 145, 137),  _target(formName)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy.getName(), 145, 137), _target(toCopy._target)
{
	*this = toCopy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopy)
{
	if(this != &toCopy)
	{

	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

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

	// outputFile << "# #### ####" << endl;
	// outputFile << "### \/#|### |/####" << endl;
	// outputFile << "##\/#/ \||/##/_/##/_#" << endl;
	// outputFile << "###  \/###|/ \/ # ###" << endl;
	// outputFile << "##_\_#\_\## | #/###_/_####" << endl;
	// outputFile << "## #### # \ #| /  #### ##/##" << endl;
	// outputFile << "__#_--###`  |{,###---###-~" << endl;
	// outputFile << "	 \ }{" << endl;
	// outputFile << "	  }}{" << endl;
	// outputFile << "	  }}{" << endl;
	// outputFile << "      {{}" << endl;
	// outputFile << ", -=-~{ .-^- _" << endl;
	// outputFile << "	  `}" << endl;
	// outputFile << "	   {" << endl;
	
	// outputFile << "   ,@@@@@@@," << endl;
	// outputFile << "   ,,,.   ,@@@@@@/@@,  .oo8888o." << endl;
	// outputFile << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o" << endl;
	// outputFile << "   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'" << endl;
	// outputFile << "   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'" << endl;
	// outputFile << "   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'" << endl;
	// outputFile << "   `&%\ ` /%&'    |.|        \ '|8'" << endl;
	// outputFile << "   |o|        | |         | |" << endl;
	// outputFile << "   |.|        | |         | |" << endl;
	
	// outputFile << "- - -" << endl;
	// outputFile << "-        -  -     --    -" << endl;
	// outputFile << "-                 -         -  -" << endl;
	// outputFile << "			 -" << endl;
	// outputFile << "			-                --" << endl;
	// outputFile << "-          -            -              -" << endl;
	// outputFile << "-            '-,        -               -" << endl;
	// outputFile << "-              'b      *" << endl;
	// outputFile << "-              '$    #-                --" << endl;
	// outputFile << "-    -           $:   #:               -" << endl;
	// outputFile << "--      -  --      *#  @):        -   - -" << endl;
	// outputFile << "	   -     :@,@):   ,-**:'   -" << endl;
	// outputFile << "-      -,         :@@*: --**'      -   -" << endl;
	// outputFile << "	'#o-    -:(@'-@*\"'  -" << endl;
	// outputFile << "-  -       'bq,--:,@@*'   ,*      -  -" << endl;
	// outputFile << "	   ,p$q8,:@)'  -p*'      -" << endl;
	// outputFile << "-     '  - '@@Pp@@*'    -  -" << endl;
	// outputFile << " -  - --    Y7'.'     -  -" << endl;
	// outputFile << "		   :@):." << endl;
	// outputFile << "		  .:@:'." << endl;
	// outputFile << "		.::(@:." << endl;
	// outputFile << "" << endl;
	
	outputFile.close();
}

const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return CREATION_FILE_FAIL_EXCEPTION;
}
