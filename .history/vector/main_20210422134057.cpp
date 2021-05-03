/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:32:30 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/22 13:40:57 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <unistd.h>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define end "\x1b[0m"


void constructor_test()
{
	std::cout << blue << "***************[ Default constructor test ]***************" << end << std::endl;
	
	std::cout << green << "Testing empty vector int: " << end << std::endl;
	ft::vector<int> vec;
	std::cout << "Vector size is: " << vec.size() << std::endl << std::endl;
}

int main()
{
	constructor_test();
	return 0;
}