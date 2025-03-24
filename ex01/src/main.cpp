/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:50:56 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::cout;
using std::endl;

int main(void)
{
	Bureaucrat a("Michel", 150);
	Bureaucrat b("Froggy", 2);
	Bureaucrat c("Pouet", 70);
	cout << a;
	cout << b;
	cout << c;
	cout << "TEST 0 --------------------------" << endl;
	try{
		Form one("first form", 40, 40);
		cout << one;
		a.signForm(one);
		b.signForm(one);
		cout << one;
		b.signForm(one);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 1 --------------------------" << endl;
	try{
		Form one("pouet form", 80, 60);
		cout << one;
		c.signForm(one);
		cout << one;
		c.signForm(one);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 2 --------------------------" << endl;
	try{
		Form one("second form", 151, 40);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 3 --------------------------" << endl;
	try{
		Form one("second form", 42, 151);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 4 --------------------------" << endl;
	try{
		Form one("third form", 0, 1);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 5 --------------------------" << endl;
	try{
		Form one("quatre form", 1, 0);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	return 0;
}
