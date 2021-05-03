/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:32:30 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/23 21:19:56 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <unistd.h>
#include <Vector>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

void print_int_array(ft::Vector<int> &vec)
{
	ft::Vector<int>::iterator it = vec.begin();
	ft::Vector<int>::iterator ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_float_array(ft::Vector<float> &vec)
{
	ft::Vector<float>::iterator it = vec.begin();
	ft::Vector<float>::iterator ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_double_array(ft::Vector<double> &vec)
{
	ft::Vector<double>::iterator it = vec.begin();
	ft::Vector<double>::iterator ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_char_array(ft::Vector<char> &vec)
{
	ft::Vector<char>::iterator it = vec.begin();
	ft::Vector<char>::iterator ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_string_array(ft::Vector<std::string> &vec)
{
	ft::Vector<std::string>::iterator it = vec.begin();
	ft::Vector<std::string>::iterator ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void constructor_test()
{
	std::cout << blue << "***************[ Default constructor test ]***************" << cend << std::endl;

	std::cout << green << "Testing empty Vector int: " << cend << std::endl;
	ft::Vector<int> vec;
	std::cout << "Vector size is: " << vec.size() << std::endl
			  << std::endl;

	std::cout << blue << "***************[ Fill constructor test ]***************" << cend << std::endl;
	std::cout << green << "Testing Vector<int> vec1(10, 42): " << cend << std::endl;
	ft::Vector<int> vec1(10, 42);
	print_int_array(vec1);
	std::cout << std::endl;

	std::cout << blue << "***************[ Range constructor test ]***************" << cend << std::endl;
	ft::Vector<int> vec2;
	for (int i = 0; i < 10; ++i)
	{
		vec2.push_back(i);
	}
	ft::Vector<int>::iterator it = vec2.begin();
	ft::Vector<int> vec3(it, it + 2);
	print_int_array(vec3);
	std::cout << std::endl;

	std::cout << blue << "***************[ Copy constructor test ]***************" << cend << std::endl;
	std::cout << green << "Making copy Vector<int> vec4(vec1): " << cend << std::endl;
	//ft::Vector<int>				vec4(vec1);
	//print_int_array(vec4);

	std::cout << blue << "***************[ Operator = test ]***************" << cend << std::endl;
	std::cout << green << "Making Vector<int> vec5 = vec1: " << cend << std::endl;
	ft::Vector<int>				vec5 = vec1;
	print_int_array(vec5);
	std::cout << std::endl;
}

void iterator_test()
{
	std::cout << blue << "***************[ Iterators test (char) ]***************" << cend << std::endl;

	ft::Vector<int> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i);
	}
	std::cout << green << "Vector contents, using iterator: " << cend << std::endl;
	print_int_array(vec);
	std::cout << green << "Vector contents in reverse, using the reverse iterator: " << cend << std::endl;

	ft::Vector<int>::reverse_iterator rit = vec.rbegin();
	ft::Vector<int>::reverse_iterator rite = vec.rend();

	while (rit != rite)
	{
		std::cout << *rit << " ";
		rit++;
	}
	std::cout << std::endl;

	std::cout << green << "Testing arithmetic operations on iterator: " << cend << std::endl;
	ft::Vector<int>::iterator it = vec.begin();
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
	ft::Vector<int>::reverse_iterator itr = vec.rbegin();
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
	ft::Vector<int> myints;
	std::cout << green << "Empty Vector: " << cend << std::endl;
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
	std::cout << green << "Taking the same Vector: " << cend << std::endl;
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
	ft::Vector<int>::size_type sz;

	ft::Vector<int> foo;
	sz = foo.capacity();
	std::cout << green << "making foo grow: " << cend << "\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	ft::Vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << green << "making bar grow: " << cend << "\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n'
					  << '\n';
		}
	}

	std::cout << blue << "***************[ empty() test (char) ]***************" << cend << std::endl;
	ft::Vector<char> vec;
	std::cout << "empty Vector: " << vec.empty() << std::endl;
	vec.push_back(5);
	std::cout << "vec not empty: " << vec.empty() << std::endl
			  << std::endl;
}

void element_access_test()
{
	std::cout << blue << "***************[ operator[] test (string) ]***************" << cend << std::endl;
	ft::Vector<std::string> myVector(10); // 10 zero-initialized elements

	myVector.push_back("have");
	myVector.push_back("a");
	myVector.push_back("good");
	myVector.push_back("day");
	myVector.push_back("!");

	ft::Vector<std::string>::size_type sz = myVector.size();
	std::cout << green << "reverse Vector using operator[]: " << cend << "\n";
	for (unsigned i = 0; i < sz / 2; i++)
	{
		std::string temp;
		temp = myVector[sz - 1 - i];
		myVector[sz - 1 - i] = myVector[i];
		myVector[i] = temp;
	}

	std::cout << "myVector contains:";
	for (unsigned i = 0; i < sz; i++)
		std::cout << ' ' << myVector[i];
	std::cout << '\n'
			  << '\n';

	std::cout << blue << "***************[ at function test (double) ]***************" << cend << std::endl;
	ft::Vector<double> dvec;
	int i = 0;

	dvec.push_back(6.025);
	dvec.push_back(42.0);
	dvec.push_back(6.669096);
	dvec.push_back(9.5);
	dvec.push_back(34.42);

	std::cout << "Initial array contents: " << std::endl;
	print_double_array(dvec);

	std::cout << green << "using at func, at(3): " << cend << "\n";
	std::cout << dvec.at(3) << std::endl;

	std::cout << blue << "***************[ front() and back() function test (double) ]***************" << cend << std::endl;
	std::cout << "front: " << dvec.front() << " | end: " << dvec.back() << std::endl;

	std::cout << std::endl;
}

void modifiers_test()
{
	std::cout << blue << "***************[ assign() test (int) ]***************" << cend << std::endl;
	ft::Vector<int> first;
	ft::Vector<int> second;
	ft::Vector<int> third;

	std::cout << green << "assign 7 ints with the value of 100 " << cend << "\n";
	first.assign(7, 100); // 7 ints with a value of 100
	std::cout << "Vector contents: " << std::endl;
	print_int_array(first);

	ft::Vector<int>::iterator it;
	it = first.begin() + 1;
	std::cout << green << "assign 5 central values of first" << cend << "\n";
	second.assign(it, first.end() - 1); // the 5 central values of first
	std::cout << "Vector contents: " << std::endl;
	print_int_array(second);

	std::cout << green << "creating array of ints {1776, 7, 4} and assigning from it: " << cend << "\n";
	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3); // assigning from array.
	std::cout << "Vector contents: " << std::endl;
	print_int_array(third);

	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
	std::cout << "Size of third: " << int(third.size()) << '\n'
			  << '\n';

	std::cout << blue << "***************[ push_back() and pop_back() test (float) ]***************" << cend << std::endl;
	ft::Vector<float> vf;
	vf.push_back(1.23f);
	vf.push_back(2.34f);
	vf.push_back(3.45f);
	vf.push_back(4.55f);
	vf.push_back(5.56f);
	std::cout << "Vector contents: " << std::endl;
	print_float_array(vf);

	std::cout << green << "calling pop_back() 2 times: " << cend << "\n";
	vf.pop_back();
	vf.pop_back();

	std::cout << "Vector contents: " << std::endl;
	print_float_array(vf);

	std::cout << blue << "***************[ insert test (int) ]***************" << cend << std::endl;
	ft::Vector<int> vi;
	for (int i = 0; i < 10; ++i)
		vi.push_back(i);
	std::cout << "Vector contents: " << std::endl;
	print_int_array(vi);
	std::cout << green << "insert 1 element at 2nd position with the value of 666 " << cend << "\n";
	it = vi.begin();
	vi.insert(it + 2, 666);
	std::cout << "Vector contents: " << std::endl;
	print_int_array(vi);
	std::cout << "Vector size: " << vi.size();
	std::cout << " | Vector capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << green << "insert 5 element at 5th position with the value of 55 " << cend << "\n";

	vi.insert(it + 5, 5, 55);
	std::cout << "Vector contents: " << std::endl;
	print_int_array(vi);
	std::cout << "Vector size: " << vi.size();
	std::cout << " | Vector capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << green << "insert range of elements int arr[] = {501,502,503} at the begin() + 1" << cend << "\n";
	int myarray[] = {501, 502, 503};
	vi.insert(vi.begin() + 1, myarray, myarray + 3);
	print_int_array(vi);
	std::cout << "Vector size: " << vi.size();
	std::cout << " | Vector capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << blue << "***************[ erase test (int) ]***************" << cend << std::endl;
	std::cout << green << "erase the 6th element: " << cend << "\n";
	vi.erase(vi.begin() + 5);
	print_int_array(vi);
	std::cout << "Vector size: " << vi.size();
	std::cout << " | Vector capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << green << "erase the first 3 elements: " << cend << "\n";
	vi.erase(vi.begin(), vi.begin() + 3);
	print_int_array(vi);
	std::cout << "Vector size: " << vi.size();
	std::cout << " | Vector capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << blue << "***************[ swap() test (string) ]***************" << cend << std::endl;
	ft::Vector<std::string> vs1;
	ft::Vector<std::string> vs2;
	vs1.push_back("chto");
	vs1.push_back("kak");
	vs1.push_back("sunshine");
	vs1.push_back("?");

	vs2.push_back("prosto");
	vs2.push_back("sdelai");
	vs2.push_back("it");

	std::cout << "Vector vs1 contents: " << std::endl;
	print_string_array(vs1);
	std::cout << "Vector vs2 contents: " << std::endl;
	print_string_array(vs2);
	
	std::cout << green << "after swapping values : " << cend << "\n";
	
	vs1.swap(vs2);
	
	std::cout << "Vector vs1 contents: " << std::endl;
	print_string_array(vs1);
	std::cout << "Vector vs2 contents: " << std::endl;
	print_string_array(vs2);

	std::cout << blue << "***************[ clear() test (string) ]***************" << cend << std::endl;
	std::cout << green << "Initial Vector contents : " << cend << "\n";
	print_string_array(vs1);
	std::cout << "Vector size: " << vs1.size();
	std::cout << " | Vector capacity: " << vs1.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << green << "Vector contents after clear() : " << cend << "\n";
	vs1.clear();
	print_string_array(vs1);
	std::cout << "Vector size: " << vs1.size();
	std::cout << " | Vector capacity: " << vs1.capacity() << std::endl;
	std::cout << std::endl;
}

	void non_member_functions()
{
	std::cout << blue << "***************[ creating 3 Vectors to test non-member functions overloads: ]***************" << cend << std::endl;
	ft::Vector<int>		v0(6, 42);
	ft::Vector<int>		v1(9, 21);
	ft::Vector<int>		v2(9, 21);
	//ft::Vector<int>		v2(v1);

	std::cout << "1st array contents: " << std::endl;
	print_int_array(v0);
	std::cout << "2nd array contents: " << std::endl;
	print_int_array(v1);
	std::cout << "3rd array contents: " << std::endl;
	print_int_array(v2);

	std::cout << blue << "***************[ operator == ]***************" << cend << std::endl;
	if (v0 == v1)
		std::cout << "v0 is equal to v1" << std::endl;
	else
		std::cout << "v0 is NOT equal to v1" << std::endl;

	// std::cout << blue << "***************[ operator != ]***************" << cend << std::endl;
	// if (v0 != v1)
	// 	std::cout << "v0 is NOT equal to v1" << std::endl;
	// else
	// 	std::cout << "v0 is equal to v1" << std::endl;

	// std::cout << blue << "***************[ operator < ]***************" << cend << std::endl;
	// if (v0 < v1)
	// 	std::cout << "v0 is less than v1" << std::endl;
	// else
	// 	std::cout << "v0 is NOT less than v1" << std::endl;

	// std::cout << blue << "***************[ operator <= ]***************" << cend << std::endl;
	// if (v0 <= v1)
	// 	std::cout << "v0 is less than or equal to v1" << std::endl;
	// else
	// 	std::cout << "v0 is NOT less than or equal to v1" << std::endl;

	// std::cout << blue << "***************[ operator > ]***************" << cend << std::endl;
	// if (v0 > v1)
	// 	std::cout << "v0 is greater than v1" << std::endl;
	// else
	// 	std::cout << "v0 is NOT greater than v1" << std::endl;

	// std::cout << blue << "***************[ operator >= ]***************" << cend << std::endl;

	// if (v1 >= v2)
	// 	std::cout << "v1 is greater than or equal to v2" << std::endl;
	// else
	// 	std::cout << "v1 is NOT greater than or equal to v2" << std::endl;

	// std::cout << blue << "***************[ swap fucntion ]***************" << cend << std::endl;

	// std::cout << "Vector v0 contents before swap: " << std::endl;
	// print_int_array(v0);
	// std::cout << "Vector v1 contents before swap: " << std::endl;
	// print_int_array(v1);
	
	// std::cout << green << "after swapping values : " << cend << "\n";
	// swap(v0, v1);
	// std::cout << "Vector v0 contents: " << std::endl;
	// print_int_array(v0);
	// std::cout << "Vector v1 contents: " << std::endl;
	// print_int_array(v1);

}

int main()
{
	//constructor_test();
	// iterator_test();
	// const_iterator_test();
	// capacity_tests();
	// element_access_test();
	// modifiers_test();
	non_member_functions();
	sleep(50);

	return 0;
}