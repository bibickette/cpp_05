/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:50:44 by phwang           ###   ########.fr       */
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
	Bureaucrat a("Michel", 150);
	Bureaucrat b("Froggy", 2);
	Bureaucrat c("Pouet", 70);
	ShrubberyCreationForm shrub("big_tree");
	RobotomyRequestForm robot("big brain");
	PresidentialPardonForm pres("La grosse betise");
	cout << a;
	cout << b;
	cout << c;
	cout << shrub;
	cout << robot;
	cout << pres;
	cout << "TEST 0 --------------------------" << endl;
	b.signForm(shrub);
	c.signForm(shrub);
	c.executeForm(shrub);
	b.executeForm(shrub);
	
	cout << endl << endl << "TEST 1 --------------------------" << endl;
	b.signForm(robot);
	a.signForm(robot);
	a.executeForm(robot);
	b.executeForm(robot);
	c.executeForm(robot);
	
	cout << endl << endl << "TEST 2 --------------------------" << endl;
	b.signForm(pres);
	a.signForm(pres);
	c.signForm(pres);
	b.executeForm(pres);
	
	return 0;
}
