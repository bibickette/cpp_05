/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 23:45:03 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

int main(void)
{
	try{
		Bureaucrat a("Jean", 70);
		Bureaucrat b("Michel", 150);
		Bureaucrat c("Pouet", 20);
		Bureaucrat d("The King", 5);

		
		ShrubberyCreationForm tree("big_tree");
		b.signForm(tree);
		c.signForm(tree);
		c.executeForm(tree);
		
		RobotomyRequestForm zzz("big brain");
		b.signForm(zzz);
		a.signForm(zzz);
		a.executeForm(zzz);
		b.executeForm(zzz);
		c.executeForm(zzz);

		PresidentialPardonForm caca("Macron Demission");
		b.signForm(caca);
		a.signForm(caca);
		c.signForm(caca);
		c.executeForm(caca);
		d.executeForm(caca);

	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	return 0;
}
