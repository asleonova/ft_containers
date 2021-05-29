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
	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator ite;
	std::map<int, int> std_map;

	std_map[2] = 200;
	std_map[3] = 300;
	std_map[1] = 200;
	std_map[3] = 500;

	// std_map[4] = 400;
	// std_map[5] = 500;
	// std_map[10] = 600;

	std::map<int, int>::iterator its;
	std::map<int, int>::iterator itse;
	its = std_map.begin();
	std::cout << "begin is: " << its->first << ", " << its->second << std::endl;
	itse = std_map.end();
	itse--;
	std::cout << "end-- is: " << itse->first << ", " << itse->second << std::endl;
	itse--;
	std::cout << "end-- is: " << itse->first << ", " << itse->second << std::endl;

	// first insert function version (single parameter)

	mymap.insert(std::pair<int, int>(5, 200));
	mymap.insert(std::pair<int, int>(4, 400));
	std::pair<ft::map<int, int>::iterator, bool> ret;
	
	ret = mymap.insert(std::pair<int, int>(6, 100));
	std::cout << "return value is (6): " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is (1): " << ret.second << '\n';
	mymap.insert(std::pair<int, int>(3, 400));
	mymap.insert(std::pair<int, int>(2, 400));
	mymap.insert(std::pair<int, int>(1, 400));
	mymap.insert(std::pair<int, int>(8, 100));
	std::cout << "return value is (8): " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is (1): " << ret.second << '\n';
	ret = mymap.insert(std::pair<int, int>(8, 100));
	std::cout << "return value is (8): " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is (0): " << ret.second << '\n';
	ret = mymap.insert(std::pair<int, int>(10, 100));
	std::cout << "return value is (10): " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is (1): " << ret.second << '\n';
	ret = mymap.insert(std::pair<int, int>(6, 100));
	std::cout << "return value is: " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is: " << ret.second << '\n';
	mymap.insert(std::pair<int, int>(7, 100));
	std::cout << "***************************" << std::endl;
	ret = mymap.insert(std::pair<int, int>(7, 100));
	std::cout << "return value is: " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is: " << ret.second << '\n';



	std::cout << "size is : " << mymap.size() << std::endl;
	mymap.treeprint();

	it = mymap.begin();
	std::cout << "begin of my map is: " << it->first << ", " << it->second << std::endl;
	// ite = mymap.end();
	// it++;
	// std::cout << "begin++ of my map is: " << it->first << ", "<< it->second << std::endl;
	// it++;
	// std::cout << "begin++ of my map is: " << it->first << ", "<< it->second << std::endl;
	// it++;
	// std::cout << "begin++ of my map is: " << it->first << ", "<< it->second << std::endl;
	// it++;
	// std::cout << "begin++ of my map is: " << it->first << ", "<< it->second << std::endl;
	// it++;
	// std::cout << "begin++ of my map is: " << it->first << ", "<< it->second << std::endl;
	// std::cout << "end is: " << ite->first << ", "<< ite->second << std::endl;

	// ite--;
	// std::cout << "end-- is: " << ite->first << ", "<< ite->second << std::endl;
	// ite--;
	// std::cout << "end-- is: " << ite->first << ", "<< ite->second << std::endl;
	// ite--;
	// std::cout << "end-- is: " << ite->first << ", "<< ite->second << std::endl;
	// std::cout << "list size is: " << lst.size() << std::endl
	// 		  << std::endl;

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
	sleep(50);
}

int main()
{
	// std::map<int, int> mapp;
	// mapp.insert(std::pair<int,int>(5, 200));
	// mapp.insert(std::pair<int,int>(10, 200));
	// std::map<int, int>::reverse_iterator rit = mapp.rend();
	// std::map<int, int>::iterator it = --mapp.begin();
	// std::cout << it->first << std::endl;

	constructor_test();
	return 0;
}