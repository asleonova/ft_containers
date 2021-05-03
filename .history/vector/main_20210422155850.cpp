/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:32:30 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/22 15:58:50 by dbliss           ###   ########.fr       */
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
	//ft::vector<int>				vec4(vec1);
	//print_int_array(vec4);

	std::cout << blue << "***************[ Copy constructor test ]***************" << cend << std::endl;
	std::cout << std::endl;

}

void iterator_test()
{
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>> [ Iterators test (ints) ] <<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::vector<int>				v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	std::cout << "\x1B[33m";
	std::cout << "Vector in direct order using classic iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>::iterator	it2 = v2.begin();
	ft::vector<int>::iterator	ite2 = v2.end();

	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Vector in reverse order using reverse_iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>::reverse_iterator	rit2 = v2.rbegin();
	ft::vector<int>::reverse_iterator	rite2 = v2.rend();

	while (rit2 != rite2)
	{
		std::cout << *rit2 << " ";
		rit2++;
	}
	std::cout << std::endl;

	// Iterator
	std::cout << "\x1B[33m";
	std::cout << "Iterator arithmetic operations test:";
	std::cout << "\033[0m\t\t" << std::endl;
	it2 = v2.begin();
	std::cout << "Initail it2: " << *it2 << std::endl;
	it2++;
	std::cout << "After it2++: " << *it2 << std::endl;
	it2--;
	std::cout << "After it2--: " << *it2 << std::endl;
	++it2;
	std::cout << "After ++it2: " << *it2 << std::endl;
	--it2;
	std::cout << "After --it2: " << *it2 << std::endl;
	it2 = it2 + 3;
	std::cout << "it2 = it2 + 3: " << *it2 << std::endl;
	it2 = it2 - 3;
	std::cout << "it2 = it2 - 3: " << *it2 << std::endl;
	it2 += 2;
	std::cout << "it2 += 2: " << *it2 << std::endl;
	it2 -= 2;
	std::cout << "it2 -= 2: " << *it2 << std::endl;
	std::cout << "it2[3]: " << it2[3] << std::endl;

}

int main()
{
	constructor_test();
	iterator_test();
	
	return 0;
}