/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:58:08 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

using std::cout;
using std::endl;

int main(void)
{
	Bureaucrat a("Michel", 150);
	Bureaucrat b("Froggy", 2);
	Bureaucrat c("Pouet", 70);
	Intern intern;
	cout << a;
	cout << b;
	cout << c;
	cout << "TEST 0 --------------------------" << endl;
	try{
		AForm *form = intern.makeForm("lala", "michel");
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 1 --------------------------" << endl;
	try{
		AForm *form = intern.makeForm("PresidentialPardonForm", "target");
		cout << *form;
		a.signForm(*form);
		cout << *form;
		a.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 2 --------------------------" << endl;
	try{
		AForm *form = intern.makeForm("ShrubberyCreationForm", "jesaispo");
		cout << *form;
		c.signForm(*form);
		cout << *form;
		c.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	return 0;
}
