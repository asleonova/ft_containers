/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:17:09 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/20 17:18:03 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Iterator.hpp"
#include <vector>
#include <iostream>
#include <unistd.h>


void	test1(void)
{
	// Capacity
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>> [ Capacity member-functions of vector class] <<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::vector<std::string>		vs0;

	vs0.push_back("May");
	vs0.push_back("the");
	vs0.push_back("Force");
	vs0.push_back("be");
	vs0.push_back("with");
	vs0.push_back("you!");

	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	std::cout << "vector max_size(): " << vs0.max_size() << std::endl;
	std::cout << std::endl;

    std::cout << "\x1B[91m";
	std::cout << ">>>>>>>> [ STD ] <<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	std::vector<std::string>		vs1;

	vs1.push_back("May");
	vs1.push_back("the");
	vs1.push_back("Force");
	vs1.push_back("be");
	vs1.push_back("with");
	vs1.push_back("you!");

	std::cout << "vector size(): " << vs1.size();
	std::cout << ", vector capacity(): " << vs1.capacity() << std::endl;
	std::cout << "vector max_size(): " << vs1.max_size() << std::endl;
	std::cout << std::endl;
}

void	test2(void)
{
	// Erase (single)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: erase (single) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "\x1B[33m";
	std::cout << "Erase element at 5th position";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.erase(it + 5);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase element at the last position";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.erase(ite - 1);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase the range elements";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::vector<int>::iterator ch1;
	ch1 = v0.erase (v0.begin() + 1,v0.begin()+3);
	std::cout << "vector's value: "<<  *ch1 << std::endl;

	
	
	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert elements";
	std::cout << "\033[0m\t\t" << std::endl;
	
	//std::vector<int>::iterator inf;
	v0.insert(v0.begin() + 5, 20, 2);
	//std::cout << "vector's value: "<<  *inf << std::endl;
	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert one element";
	std::cout << "\033[0m\t\t" << std::endl;
	
	//std::vector<int>::iterator inf;
	v0.insert(v0.begin() + 1, 15);
	//std::cout << "vector's value: "<<  *inf << std::endl;
	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;
	std::cout << std::endl;







	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ STD ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	std::vector<int>		v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);

	std::vector<int>::iterator	its = v1.begin();
	std::vector<int>::iterator	ites = v1.end();

	std::cout << "Initial array:" << std::endl;
	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;
	its = v1.begin();

	std::cout << "\x1B[33m";
	std::cout << "Erase element at 5th position";
	std::cout << "\033[0m\t\t" << std::endl;

	v1.erase(its + 5);

	its = v1.begin();
	ites = v1.end();

	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase element at the last position";
	std::cout << "\033[0m\t\t" << std::endl;

	

	std::vector<int>::iterator er;
	er = v1.erase(ites - 1);
	std::cout << "vector's value: "<<  *er << std::endl;

	its = v1.begin();
	ites = v1.end();

	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase the range elements";
	std::cout << "\033[0m\t\t" << std::endl;
	
	std::vector<int>::iterator ch;
	ch = v1.erase (v1.begin() + 1,v1.begin()+3);
	std::cout << "vector's value: "<<  *ch << std::endl;
	its = v1.begin();
	ites = v1.end();

	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert elements";
	std::cout << "\033[0m\t\t" << std::endl;
	
	std::vector<int>::iterator in;
	in = v1.insert(v1.begin() + 5, 20, 2);
	std::cout << "vector's value: "<<  *in << std::endl;
	its = v1.begin();
	ites = v1.end();

	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert one element: STD";
	std::cout << "\033[0m\t\t" << std::endl;
	
	//std::vector<int>::iterator inf;
	v1.insert(v1.begin() + 1, 15);
	//std::cout << "vector's value: "<<  *inf << std::endl;
	its = v1.begin();
	ites = v1.end();

	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;
	std::cout << std::endl;
}

void	test3(void)
{
	// Capacity
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>> [ Capacity member-functions of vector class] <<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::vector<std::string>		vs0;

	vs0.push_back("May");
	vs0.push_back("the");
	vs0.push_back("Force");
	vs0.push_back("be");
	vs0.push_back("with");
	vs0.push_back("you!");

	ft::vector<std::string>::iterator	it = vs0.begin();
	ft::vector<std::string>::iterator	ite = vs0.end();

	std::vector<std::string>		vs1;

	vs1.push_back("May");
	vs1.push_back("the");
	vs1.push_back("Force");
	vs1.push_back("be");
	vs1.push_back("with");
	vs1.push_back("you!");

	std::vector<std::string>::iterator	its = vs1.begin();
	std::vector<std::string>::iterator	ites = vs1.end();

	std::cout << "\x1B[33m";
	std::cout << "Initial vector content:";
	std::cout << "\033[0m\t\t" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	std::cout << "vector max_size(): " << vs0.max_size() << std::endl;
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "STD::Initial vector content:";
	std::cout << "\033[0m\t\t" << std::endl;
	while (its != ites)
	{
		std::cout << *its << std::endl;
		its++;
	}
	std::cout << "vector size(): " << vs1.size();
	std::cout << ", vector capacity(): " << vs1.capacity() << std::endl;
	std::cout << "vector max_size(): " << vs1.max_size() << std::endl;
	std::cout << std::endl;

	// Resize to 10
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 10 with \"!\" values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(10, "!");
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Resize to 10 (std)
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 10 with \"!\" values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs1.resize(10, "!");
	std::cout << "vector size(): " << vs1.size();
	std::cout << ", vector capacity(): " << vs1.capacity() << std::endl;
	its = vs1.begin();
	ites = vs1.end();
	while (its != ites)
	{
		std::cout << *its << std::endl;
		its++;
	}

	// // Resize to 12 by default
	// std::cout << "\x1B[33m";
	// std::cout << "Resize vector to 12 by default values";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs0.resize(12);
	// std::cout << "vector size(): " << vs0.size();
	// std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	// it = vs0.begin();
	// ite = vs0.end();
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }

	// // Resize to 12 by default
	// std::cout << "\x1B[33m";
	// std::cout << "Resize vector to 12 by default values";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs1.resize(12);
	// std::cout << "vector size(): " << vs1.size();
	// std::cout << ", vector capacity(): " << vs1.capacity() << std::endl;
	// its = vs1.begin();
	// ites = vs1.end();
	// while (its != ites)
	// {
	// 	std::cout << *its << std::endl;
	// 	its++;
	// }

	// // Resize to 5 by default
	// std::cout << "\x1B[33m";
	// std::cout << "Resize vector to 5 by default values";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs0.resize(5);
	// std::cout << "vector size(): " << vs0.size();
	// std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	// it = vs0.begin();
	// ite = vs0.end();
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }

	// 	// Resize to 5 by default
	// std::cout << "\x1B[33m";
	// std::cout << "Resize vector to 5 by default values";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs1.resize(5);
	// std::cout << "vector size(): " << vs1.size();
	// std::cout << ", vector capacity(): " << vs1.capacity() << std::endl;
	// its = vs1.begin();
	// ites = vs1.end();
	// while (its != ites)
	// {
	// 	std::cout << *its << std::endl;
	// 	its++;
	// }

	// // Resize to 3 with "!"
	// std::cout << "\x1B[33m";
	// std::cout << "Resize vector to 3 with \"!\" value";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs0.resize(3, "!");
	// std::cout << "vector size(): " << vs0.size();
	// std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	// it = vs0.begin();
	// ite = vs0.end();
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }


	// // Resize to 3 with "!"
	// std::cout << "\x1B[33m";
	// std::cout << "Resize vector to 3 with \"!\" value";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs1.resize(3, "!");
	// std::cout << "vector size(): " << vs1.size();
	// std::cout << ", vector capacity(): " << vs1.capacity() << std::endl;
	// its = vs1.begin();
	// ites = vs1.end();
	// while (its != ites)
	// {
	// 	std::cout << *its << std::endl;
	// 	its++;
	// }


	// // Reserve 50
	// std::cout << "\x1B[33m";
	// std::cout << "Reserve 50 for vector";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs0.reserve(50);
	// std::cout << "vector size(): " << vs0.size();
	// std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	// it = vs0.begin();
	// ite = vs0.end();
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }

	// if (vs0.empty())
	// 	std::cout << "The vector is empty" << std::endl;
	// std::cout << std::endl;

	// 	// Reserve 50
	// std::cout << "\x1B[33m";
	// std::cout << "Reserve 50 for vector";
	// std::cout << "\033[0m\t\t" << std::endl;
	// vs1.reserve(50);
	// std::cout << "vector size(): " << vs1.size();
	// std::cout << ", vector capacity(): " << vs1.capacity() << std::endl;
	// its = vs1.begin();
	// ites = vs1.end();
	// while (its != ites)
	// {
	// 	std::cout << *its << std::endl;
	// 	its++;
	// }

	// if (vs1.empty())
	// 	std::cout << "The vector is empty" << std::endl;
	// std::cout << std::endl;
}

void	test4(void)
{
	// Erase (range)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: erase (range) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();


	std::vector<int>		v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);

	std::vector<int>::iterator	its = v1.begin();
	std::vector<int>::iterator	ites = v1.end();

	std::cout << "Initial array:" << std::endl;
	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;
	its = v1.begin();

	std::cout << "\x1B[33m";
	std::cout << "Erase element from 1 to 4 position";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.erase(it + 1, it + 4);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "STD:: Erase element from 1 to 4 position";
	std::cout << "\033[0m\t\t" << std::endl;

	v1.erase(its + 1, its + 4);

	its = v1.begin();
	ites = v1.end();

	while (its != ites)
	{
		std::cout << *its << " ";
		its++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;



	std::cout << "\x1B[33m";
	std::cout << "Erase element with same iterators";
	std::cout << "\033[0m\t\t" << std::endl;

	it = v0.begin();

	ft::vector<int>::iterator	ret = v0.erase(it + 1, it + 1);
	std::cout << "ret: " << *ret << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "STD::Erase element with same iterators";
	std::cout << "\033[0m\t\t" << std::endl;

	its = v1.begin();

	std::vector<int>::iterator	rets = v1.erase(its + 1, its + 1);
	std::cout << "ret: " << *rets << std::endl;

	std::cout << std::endl;
}

void	test_swap(void)
{
	// Swap
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: swap ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;
	ft::vector<int>		v1(10, 42);

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	ite1 = v1.end();

	std::cout << "Initial array 1:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Initial array 2:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Swap:";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.swap(v1);

	it = v0.begin();
	ite = v0.end();

	it1 = v1.begin();
	ite1 = v1.end();

	std::cout << "Array 1 after swap:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Array 2 after swap:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "*****************STD***************************" << std::endl;

}

void test_swap_std()
{

	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: swap ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	std::vector<int>		v0;
	std::vector<int>		v1(10, 42);

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	std::vector<int>::iterator	it = v0.begin();
	std::vector<int>::iterator	ite = v0.end();

	std::vector<int>::iterator	it1 = v1.begin();
	std::vector<int>::iterator	ite1 = v1.end();

	std::cout << "Initial array 1:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Initial array 2:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Swap:";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.swap(v1);

	it = v0.begin();
	ite = v0.end();

	it1 = v1.begin();
	ite1 = v1.end();

	std::cout << "Array 1 after swap:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Array 2 after swap:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << std::endl;
}


int main()
{
    //test1();
	//test2();
	//test3();
	//test4();
	test_swap();
	test_swap_std();
    std::vector<int>vec;
    ft::vector<int> v;

	// TO DO:  test erase func with the range!!!!
    v.push_back(1);
    v.push_back(10);
    v.push_back(4);
    std::cout << v.size() << std::endl;
    v.pop_back();
    v.pop_back();
    std::cout << v.size() << std::endl;


    vec.push_back(1);
    vec.push_back(10);
    vec.push_back(4);
    std::cout << vec.size() << std::endl;
    vec.pop_back();
    std::cout << vec.size() << std::endl;
    sleep(50);
    //ft::vector<int>::iterator it;
    //ft::vector<int>::reverse_iterator rev_it;
    //ft::vector<int> v1(4);
    // v1.begin();
    //  v1.end();
    // it++;
   // rev_it++;
    return 0;
}