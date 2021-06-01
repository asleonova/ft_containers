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

template <class Key, class T>
void print_map(ft::map<Key, T> &map)
{
	typename ft::map<Key, T>::iterator it = map.begin();
	typename ft::map<Key, T>::iterator ite = map.end();
	while (it != ite)
	{
		std::cout << it->first << " ," << it->second << " | ";
		++it;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void constructor_test()
{
	std::cout << blue << "***************[ Default constructor test ]***************" << cend << std::endl;

	std::cout << green << "Testing empty map int: " << cend << std::endl;
	ft::map<int, int> mymap;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator ite;

	std::map<int, int>::iterator its;
	std::map<int, int>::iterator ites;
	std::map<int, int> std_map;

	// std_map[2] = 200;
	// std_map[3] = 300;
	// std_map[1] = 200;
	// std_map[3] = 500;

	// std_map[4] = 400;
	// std_map[5] = 500;
	// std_map[10] = 600;

	// std::map<int, int>::iterator its;
	// std::map<int, int>::iterator itse;
	// its = std_map.begin();
	// std::cout << "begin is: " << its->first << ", " << its->second << std::endl;
	// itse = std_map.end();
	// itse--;
	// std::cout << "end-- is: " << itse->first << ", " << itse->second << std::endl;
	// itse--;
	// std::cout << "end-- is: " << itse->first << ", " << itse->second << std::endl;

	// first insert function version (single parameter)

	std::cout << "***************?//////////STD////////////////?*******************" << std::endl;

	std_map.insert(std::pair<int, int>(5, 200));
	std_map.insert(std::pair<int, int>(4, 400));
	std::pair<std::map<int, int>::iterator, bool> ret1;

	ret1 = std_map.insert(std::pair<int, int>(6, 100));
	std::cout << "return value is (6): " << ret1.first->first << '\n';
	std::cout << " with a value of " << ret1.first->second << '\n';
	std::cout << "bool value is (1): " << ret1.second << '\n';
	std_map.insert(std::pair<int, int>(3, 400));
	std_map.insert(std::pair<int, int>(2, 400));
	std_map.insert(std::pair<int, int>(1, 400));
	std_map.insert(std::pair<int, int>(8, 100));
	std::cout << "return value is (8): " << ret1.first->first << '\n';
	std::cout << " with a value of " << ret1.first->second << '\n';
	std::cout << "bool value is (1): " << ret1.second << '\n';
	ret1 = std_map.insert(std::pair<int, int>(8, 100));
	std::cout << "return value is (8): " << ret1.first->first << '\n';
	std::cout << " with a value of " << ret1.first->second << '\n';
	std::cout << "bool value is (0): " << ret1.second << '\n';
	ret1 = std_map.insert(std::pair<int, int>(10, 100));
	std::cout << "return value is (10): " << ret1.first->first << '\n';
	std::cout << " with a value of " << ret1.first->second << '\n';
	std::cout << "bool value is (1): " << ret1.second << '\n';
	ret1 = std_map.insert(std::pair<int, int>(6, 100));
	std::cout << "return value is (6): " << ret1.first->first << '\n';
	std::cout << " with a value of " << ret1.first->second << '\n';
	std::cout << "bool value is (0): " << ret1.second << '\n';
	std_map.insert(std::pair<int, int>(7, 100));
	ret1 = std_map.insert(std::pair<int, int>(7, 100));
	std::cout << "return value is (7): " << ret1.first->first << '\n';
	std::cout << " with a value of " << ret1.first->second << '\n';
	std::cout << "bool value is (0): " << ret1.second << '\n';

	its = std_map.begin();
	ites = std_map.end();

	while (its != ites)
	{
		std::cout << "contents of my map: " << its->first << ", " << its->second << std::endl;
		++its;
	}

	its = std_map.begin();
	ites = std_map.end();

	while (ites != its)
	{
		std::cout << "end is: " << ites->first << std::endl;
		ites--;
	}

	std::cout << "size is : " << std_map.size() << std::endl;

	std::cout << "**************************MY FUNCS********************************" << std::endl;

	mymap[1] = 200;
	mymap[3] = 500;
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
	std::cout << "return value is (6): " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is (0): " << ret.second << '\n';
	mymap.insert(std::pair<int, int>(7, 100));
	ret = mymap.insert(std::pair<int, int>(7, 100));
	std::cout << "return value is (7): " << ret.first->first << '\n';
	std::cout << " with a value of " << ret.first->second << '\n';
	std::cout << "bool value is (0): " << ret.second << '\n';
	mymap.insert(std::pair<int, int>(9, 100));
	//mymap.erase(7);

	it = mymap.begin();
	ite = mymap.end();
	while (ite != it)
	{
		std::cout << "end is: " << ite->first << std::endl;
		ite--;
	}

	ft::map<int, int> anothermap;
	ft::map<int, int> anothermap1;
	anothermap.insert(mymap.begin(), mymap.end());

	anothermap1 = anothermap;

	std::cout << "begin is: " << mymap.begin()->first << std::endl;
	std::cout << "end is: " << ite->first << std::endl;
	//print_map(mymap);

	std::cout << "size is : " << mymap.size() << std::endl;
	mymap.treeprint();

	it = mymap.begin();
	ite = mymap.end();
	while (it != ite)
	{
		std::cout << "contents of my map: " << it->first << ", " << it->second << std::endl;
		++it;
	}
	ft::map<int, int>::iterator it2;
	ft::map<int, int>::iterator ite2;
	it2 = anothermap.begin();
	ite2 = anothermap.end();
	while (it2 != ite2)
	{
		std::cout << "contents of another map: " << it2->first << ", " << it2->second << std::endl;
		++it2;
	}
	ft::map<int, int> mymap2;
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
	// 	it++;
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
	//sleep(50);
}

void erase_func_test()
{
	std::cout << blue << "***************[ Erase func test ]***************" << cend << std::endl;
	ft::map<int, int> mymap;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator ite;

	// insert some values:
	mymap[1] = 10;
	mymap[2] = 20;
	mymap[3] = 30;
	mymap[4] = 40;
	mymap[5] = 50;
	mymap[6] = 60;
	mymap[7] = 70;
	mymap[8] = 80;
	mymap[9] = 90;
	mymap[10] = 100;


	// it = mymap.begin();
	// it++;
	// std::cout << "it calue is: " << it->first << std::endl;
	// it = mymap.find('b');
	//mymap.erase(it); // erasing by iterator

	mymap.treeprint();
	mymap.erase(3); // erasing by key
	std::cout << "__________after erase 3_________________________" << std::endl << std::endl;
	mymap.treeprint();
	mymap.erase(4); // erasing by key
	std::cout << "__________after erase 4________________________" << std::endl << std::endl;
	mymap.treeprint();
	std::cout << "__________after erase 6____________" << std::endl << std::endl;
	mymap.erase(6); // erasing by key
	mymap.treeprint();

	it = mymap.begin();
	std::cout << it->first;

	//it++;
	// it = mymap.find('e');
	//mymap.erase(it, mymap.end()); // erasing by range

	// show content:
	// for (it = mymap.begin(); it != mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

}

int main()
{
	
	// std::map<int, int> mapp;
	// mapp.insert(std::pair<int,int>(5, 200));
	// mapp.insert(std::pair<int,int>(10, 200));
	// std::map<int, int>::reverse_iterator rit = --mapp.rend();
	// // std::map<int, int>::iterator it = --mapp.begin();
	// std::cout << rit->first << std::endl;

	constructor_test();
	erase_func_test();
	return 0;
}