/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 18:16:58 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

int main(void)
{
	try{
		Bureaucrat a("Champignon", 0);
		cout << a;
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	try{
		Bureaucrat a("Chips", 151);
		cout << a;
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	try{
		Bureaucrat a("Pouet", 70);
		cout << a;
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	return 0;
}
