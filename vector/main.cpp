/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:17:09 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/16 21:08:03 by dbliss           ###   ########.fr       */
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
}


int main()
{
    test1();
    std::vector<int>vec;
    ft::vector<int> v;
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