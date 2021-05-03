/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:32:30 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/22 15:11:04 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"


void print_int_array(ft::vector<int> &vec)
{
	ft::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;

}

void constructor_test()
{
	std::cout << blue << "***************[ Default constructor test ]***************" << cend << std::endl;
	
	std::cout << green << "Testing empty vector int: " << cend << std::endl;
	ft::vector<int> vec;
	std::cout << "Vector size is: " << vec.size() << std::endl << std::endl;

	std::cout << blue << "***************[ Fill constructor test ]***************" << cend << std::endl;
	std::cout << green << "Testing vector<int> vec1(10, 42): " << cend << std::endl;
	ft::vector<int> vec1(10, 42);
	print_int_array(vec1);
	std::cout << std::endl;

	std::cout << blue << "***************[ Range constructor test ]***************" << cend << std::endl;
	ft::vector<int> vec2;
	for (int i = 0; i < 10; ++i)
	{
		vec2.push_back(i);
	}
	ft::vector<int>::iterator it = vec2.begin();
	ft::vector<int> vec3(it, it + 2);
	print_int_array(vec3);
	std::cout << std::endl;

	std::cout << blue << "***************[ Copy constructor test ]***************" << cend << std::endl;
	std::cout << green << "Making copy vector<int> vec4(vec1): " << cend << std::endl;
	ft::vector<int>				vec4 = vec1);
	print_int_array(vec4);
	std::cout << std::endl;



}

int main()
{
	constructor_test();
	return 0;
}