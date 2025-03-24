/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:34:40 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

int main(void)
{
	cout << "TEST 0 --------------------------" << endl;
	try{
		Bureaucrat a("Michel", 0);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 1 --------------------------" << endl;
	
	try{
		Bureaucrat a("Froggy", 149);
		cout << a;
		a.decrementGrade();
		cout << a;
		a.decrementGrade();
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	cout << endl << endl << "TEST 2 --------------------------" << endl;

	try{
		Bureaucrat a("Pouet", 2);
		cout << a;
		a.incrementGrade();
		cout << a;
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	return 0;
}
