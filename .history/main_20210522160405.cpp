#include "Map.hpp"
#include <memory>
#include <map>
#include <unistd.h>
#include <cmath>
#include <iterator>
#include <iostream>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"


void constructor_test()
{
	std::cout << blue << "***************[ Default constructor test ]***************" << cend << std::endl;

	std::cout << green << "Testing empty map int: " << cend << std::endl;
	ft::map<int, int> mymap;
	ft::map<char, int>::iterator it;
	ft::map<char, int>::iterator ite;
	std::map<int,int> std_map;

	std_map[2] = 200;
  	std_map[3] = 300;
	std_map[1] = 100;

	// std_map[4] = 400;
	// std_map[5] = 500;
	// std_map[10] = 600;

	std::map<int, int>::iterator its;
	std::map<int, int>::iterator itse;
	its = std_map.begin();
	std::cout << "begin is: " << its->first << ", "<< its->second << std::endl;
	itse = std_map.end();
	//itse--;
	std::cout << "end is: " << itse->first << ", "<< itse->second << std::endl;

  // first insert function version (single parameter)
	
 	 mymap.insert ( std::pair<int,int>(2, 200) );
	  mymap.insert(std::pair<int, int>(3, 300));
	 mymap.insert(std::pair<int, int>(1, 100));

	 it = mymap.begin();
	std::cout << "begin of my map is: " << it->first << ", "<< it->second << std::endl;
	ite = mymap.end();
	// //ite--;
	std::cout << "end is: " << ite->first << ", "<< ite->second << std::endl;
//	std::cout << "list size is: " << lst.size() << std::endl
//			  << std::endl;

	/*std::cout << blue << "***************[ Fill constructor test ]***************" << cend << std::endl;
	std::cout << green << "Testing list<int> lst1(10, 42): " << cend << std::endl;
	ft::list<int> lst1(10, 42);
	print_list(lst1);
	std::cout << std::endl;

	std::cout << blue << "***************[ Range constructor test ]***************" << cend << std::endl;
	ft::list<int> lst2;
	for (int i = 0; i < 10; ++i)
	{
		lst2.push_back(i);
	}
	ft::list<int>::iterator it = lst2.begin();
	ft::list<int>::iterator ite = lst2.end();
	ft::list<int> lst3(it, ite);
	print_list(lst3);
	std::cout << std::endl;

	std::cout << blue << "***************[ Copy constructor test ]***************" << cend << std::endl;
	std::cout << green << "Making copy list<int> lst4(lst1): " << cend << std::endl;
	ft::list<int> lst4(lst1);
	print_list(lst4);

	std::cout << blue << "***************[ Operator = test ]***************" << cend << std::endl;
	std::cout << green << "Making list<int> lst5 = lst1: " << cend << std::endl;
	ft::list<int> lst5(10, 4);
	lst1 = lst5;
	print_list(lst1);
	std::cout << std::endl;
    */
}

int main()
{
    constructor_test();
    return 0;
}