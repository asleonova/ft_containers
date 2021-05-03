/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:32:30 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/23 14:00:00 by dbliss           ###   ########.fr       */
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
	ft::vector<int>::iterator it = vec.begin();
	ft::vector<int>::iterator ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_char_array(ft::vector<char> &vec)
{
	ft::vector<char>::iterator it = vec.begin();
	ft::vector<char>::iterator ite = vec.end();
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
	std::cout << "Vector size is: " << vec.size() << std::endl
			  << std::endl;

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
	std::cout << blue << "***************[ Iterators test (char) ]***************" << cend << std::endl;

	ft::vector<int> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i);
	}
	std::cout << green << "Vector contents, using iterator: " << cend << std::endl;
	print_int_array(vec);
	std::cout << green << "Vector contents in reverse, using the reverse iterator: " << cend << std::endl;

	ft::vector<int>::reverse_iterator rit = vec.rbegin();
	ft::vector<int>::reverse_iterator rite = vec.rend();

	while (rit != rite)
	{
		std::cout << *rit << " ";
		rit++;
	}
	std::cout << std::endl;

	std::cout << green << "Testing arithmetic operations on iterator: " << cend << std::endl;
	ft::vector<int>::iterator it = vec.begin();
	std::cout << "it value: " << *it << std::endl;
	it++;
	std::cout << "it++ value: " << *it << std::endl;
	it--;
	std::cout << "it-- value: " << *it << std::endl;
	++it;
	std::cout << "++it value: " << *it << std::endl;
	--it;
	std::cout << "--it value: " << *it << std::endl;
	it = it + 5;
	std::cout << "it = it + 5: " << *it << std::endl;
	it = it - 2;
	std::cout << "it = it - 2: " << *it << std::endl;
	it += 3;
	std::cout << "it += 3: " << *it << std::endl;
	it -= 3;
	std::cout << "it -= 3: " << *it << std::endl;
	bool b = (it == it + 1);
	std::cout << "it == it + 1: " << b << std::endl;
	b = (it != it + 1);
	std::cout << "it != it + 1: " << b << std::endl;
	b = (it > it + 1);
	std::cout << "it > it + 1: " << b << std::endl;
	b = (it >= it);
	std::cout << "it >= it: " << b << std::endl;
	b = (it < it);
	std::cout << "it < it: " << b << std::endl;
	b = (it <= it + 1);
	std::cout << "it <= it + 1: " << b << std::endl;
	std::cout << "it[0]: " << it[0] << std::endl;

	std::cout << green << "Testing arithmetic operations on reverse iterator: " << cend << std::endl;
	ft::vector<int>::reverse_iterator itr = vec.rbegin();
	std::cout << "itr value: " << *itr << std::endl;
	itr++;
	std::cout << "itr++ value: " << *itr << std::endl;
	itr--;
	std::cout << "itr-- value: " << *itr << std::endl;
	++itr;
	std::cout << "++itr value: " << *itr << std::endl;
	--itr;
	std::cout << "--itr value: " << *itr << std::endl;
	itr = itr + 5;
	std::cout << "itr = itr + 5: " << *itr << std::endl;
	itr = itr - 2;
	std::cout << "itr = itr - 2: " << *itr << std::endl;
	itr += 3;
	std::cout << "itr += 3: " << *itr << std::endl;
	itr -= 3;
	std::cout << "itr -= 3: " << *itr << std::endl;
	std::cout << "itr[0]: " << itr[0] << std::endl;
}

void const_iterator_test()
{
	std::cout << "I'll make tests, promise!" << std::endl;
}

void capacity_tests()
{
	std::cout << blue << "***************[ size() test (int) ]***************" << cend << std::endl;
	ft::vector<int> myints;
	std::cout << green << "Empty vector: " << cend << std::endl;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	std::cout << green << "After push_back 10 elements: " << cend << std::endl;
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert(myints.end(), 10, 100);
	std::cout << green << "After inserting 10 elements: " << cend << std::endl;
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << green << "After popback(): " << cend << std::endl;
	std::cout << "3. size: " << myints.size() << '\n'
			  << '\n';

	std::cout << blue << "***************[ max_size() test (int) ]***************" << cend << std::endl;
	std::cout << green << "Taking the same vector: " << cend << std::endl;
	std::cout << "size: " << myints.size() << "\n";
	std::cout << "capacity: " << myints.capacity() << "\n";
	std::cout << "max_size: " << myints.max_size() << "\n"
			  << "\n";

	std::cout << blue << "***************[ resize() test (int) ]***************" << cend << std::endl;
	myints.resize(5);
	std::cout << green << "myints.resize(5): " << cend << std::endl;
	print_int_array(myints);
	std::cout << green << "myints.resize(8, 100): " << cend << std::endl;
	myints.resize(8, 100);
	print_int_array(myints);
	myints.resize(12);
	std::cout << green << "myints.resize(12): " << cend << std::endl;
	print_int_array(myints);
	std::cout << '\n';

	std::cout << blue << "***************[ reserve() test (int) ]***************" << cend << std::endl;
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << green << "making foo grow: "<< cend << "\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100); // this is the only difference with foo above
	std::cout << green << "making bar grow: "<< cend << "\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

int main()
{
	constructor_test();
	iterator_test();
	const_iterator_test();
	capacity_tests();

	return 0;
}