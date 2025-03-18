/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 00:39:39 by phwang           ###   ########.fr       */
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
	Intern pouet;
	Bureaucrat a("TheKing", 1);
	try{
		// {
		// 	AForm *form = pouet.makeForm("lala", "michel");
		// }
		{
			AForm *form = pouet.makeForm("PresidentialPardonForm", "michel");
			cout << *form;
			a.signForm(*form);
			cout << *form;
			a.executeForm(*form);

			delete form;
		}
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	return 0;
}
