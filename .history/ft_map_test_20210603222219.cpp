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

# define CLR_GRN "\033[0;32m"
# define CLR_YLW "\033[0;33m"
# define CLR_BLU "\033[0;34m"
# define CLR_RED "\033[0;31m"
# define CLR_PRP "\033[0;35m"
# define CLR_END "\033[0m"

# define ENDL			std::cout << std::endl;
# define PRT(x)			std::cout << x
# define PRINT(x)		std::cout << x << std::endl
# define PRINT_YLW(x)	PRINT("\n " << CLR_YLW << x << CLR_END);
# define PRINT_PRP(x)	PRINT("\n " << CLR_PRP << x << CLR_END << "\n");
# define PRT_BLU(x)		PRT(CLR_BLU << x << ": " << CLR_END);
# define PRINT_BLU(x)	PRINT(CLR_BLU << x << ":" << CLR_END);



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
	its++;
	its++;
	its++;
	ites = std_map.insert(its, std::pair<int, int>(17, 89));
	std::cout << "Iterator return position value: " << ites->first << std::endl;

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
	it = mymap.begin();
	it++;
	it++;
	it = mymap.insert(it, std::pair<int, int>(17, 89));
	std::cout << "ITER VALUE IS:::: " << it->first << std::endl;
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
	it = anothermap.begin();
	std::cout << "map begin: " << it->first << std::endl;
	std::cout << "map end: " << anothermap.end()->first << std::endl;

	//anothermap.clear();
	// std::cout << "_________________________________" << std::endl;
	
	// std::cout << "IT value is: " << it->first << std::endl;
	// anothermap.erase(1); // 1
	// std::cout << "________________1_______________" << std::endl;
	// std::cout << "IT value is: " << it->first << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(2); // 2
	// 	std::cout << "______________2__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(3); //3
	// 		std::cout << "______________3__________________" << std::endl;
	// anothermap.treeprint();	
	// anothermap.erase(4); //4
	// 		std::cout << "______________4__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(5);//5
	// 		std::cout << "______________5__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(6);//6
	// 		std::cout << "______________6__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(7); //7
	// 		std::cout << "______________7__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(8); //8
	// 		std::cout << "______________8__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(9); //9
	// 		std::cout << "______________9__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(10); //10
	// 		std::cout << "______________10__________________" << std::endl;
	// anothermap.treeprint();
	// anothermap.erase(17);
	// std::cout << "______________17__________________" << std::endl;


	
	anothermap.clear();
	//anothermap.erase(anothermap.begin(), anothermap.end());
	//anothermap.treeprint();
	std::cout << "mymap size is: " << anothermap.size() << std::endl;
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

	std::cout << "SIZE SHOULD BE 10: " << mymap.size() << std::endl;

	std::map<int, int> mymapp;

	// insert some values:
	mymapp[1] = 10;
	mymapp[2] = 20;
	mymapp[3] = 30;
	mymapp[4] = 40;
	mymapp[5] = 50;
	mymapp[6] = 60;
	mymapp[7] = 70;
	mymapp[8] = 80;
	mymapp[9] = 90;
	mymapp[10] = 100;

	std::cout << "SIZE SHOULD BE 10 (SSTD): " << mymapp.size() << std::endl;


	it = mymap.begin();
	it++;
	std::cout << "it calue is: " << it->first << std::endl;
	// it = mymap.find('b');


	mymap.treeprint();
	mymap.erase(3); // erasing by key
	std::cout << "__________after erase 3_________________________" << std::endl << std::endl;
	mymap.treeprint();
	std::cout << "__________after erase 2_________________________" << std::endl << std::endl;
	mymap.erase(it); // erasing by iterator
	mymap.treeprint();
	mymap.erase(4); // erasing by key
	std::cout << "__________after erase 4________________________" << std::endl << std::endl;
	mymap.treeprint();
	std::cout << "__________after erase 6____________" << std::endl << std::endl;
	mymap.erase(6); // erasing by key
	mymap.treeprint();


	std::cout << "Adding more values" << std::endl;
	mymap[2] = 20;
	mymap[3] = 30;
	mymap[4] = 40;

	it = mymap.begin();
	std::cout << it->first;
	ite = mymap.end();
	std::cout << " ,"<< ite->first << std::endl;

	it++;
	// it = mymap.find('e');
	mymap.erase(mymap.begin(), mymap.end()); // erasing by range
	std::cout << "__________after erasing range____________" << std::endl << std::endl;
	// //mymap.treeprint();

	// std::cout << "size is: " << mymap.size() << std::endl;


	// show content:
	// for (; it != ite; ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';
}

void find_std_func()
{
	std::cout << blue << "***************[ FIND && REVERSE_ITERATOR func test STD]***************" << cend << std::endl;
	std::map<char,int> mymap;
  	std::map<char,int>::iterator it;
	std::map<char, int>::reverse_iterator rit;
	std::map<char, int>:: reverse_iterator rite;


  	mymap['a']=50;
  	mymap['b']=100;
  	mymap['c']=150;
  	mymap['d']=200;
	mymap['t']=600;
	mymap['o']=800;
	mymap['i']=500;
	mymap['l']=100; 


  	it = mymap.find('b');
  	if (it != mymap.end())
    	mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  std::cout << "reverse iterator test: " << std::endl;
  rit = mymap.rbegin();
  rite = mymap.rend();
  rite--;
  std::cout << rite->first << std::endl;
 
  
  rit++;
  std::cout << "reverse iterator: " << std::endl;
  std::cout << rite->first << std::endl;
  std::cout << rit->first << std::endl;
  while (rit != rite)
	{
		std::cout << rit->first << " | ";
		rit++;
	}
	std::cout << std::endl;
}


void find_func()
{
	std::cout << blue << "***************[ FIND && REVERSE_ITERATOR func test FT]***************" << cend << std::endl;	
	ft::map<char,int> mymap;
  	ft::map<char,int>::iterator it;
	ft::map<char, int>::reverse_iterator rit;
	ft::map<char, int>:: reverse_iterator rite;

  	mymap['a']=50;
  	mymap['b']=100;
  	mymap['c']=150;
  	mymap['d']=200;
	mymap['t']=600;
	mymap['o']=800;
	mymap['i']=500;
	mymap['l']=100; 


  	it = mymap.find('b');
  	if (it != mymap.end())
    	mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  std::cout << "reverse iterator test: " << std::endl;
  rit = mymap.rbegin();
  rite = mymap.rend();
  rite--;
  std::cout << rite->first << std::endl;
 
  
  rit++;
  std::cout << "reverse iterator: " << std::endl;
  std::cout << rite->first << std::endl;
  std::cout << rit->first << std::endl;
  while (rit != rite)
	{
		std::cout << rit->first << " | ";
		rit++;
	}
}

void count_func()
{
	std::cout << std::endl;
	std::cout << std::endl;
	  ft::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
}

void		map_base()
{
	PRINT_YLW("\n---| map base tests | ---")
	PRINT(CLR_YLW "\n-- constructing map" CLR_END);// ------- constructing queues ---------------
	{
		PRINT_BLU("std")
		std::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::map<char,int> second (first.begin(),first.end());
		std::map<char,int> third (second);
		std::map<char,int,classcomp> fourth;
		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
		PRINT("1 :" << first.begin()->second << "|");
		PRINT("2 :" << (*first.begin()).second << "|");

		ENDL
		std::map<char,std::string> test;
		PRT("size :" << test.size() << "|");
		test['a']="7";		PRT(" " << test.size() << "|");
		test['c']="21";		PRT(" " << test.size() << "|");
		test['e']="42";		PRT(" " << test.size() << "|");
		test['b']="13";		PRT(" " << test.size() << "|");
		test['d']="26";		PRINT(" " << test.size() << "|");
		std::map<char,std::string>::iterator		it = test.begin();
		std::map<char,std::string>::iterator		ite = test.end();
		int i = 0;
		for(; it != ite; ++it, ++i)
			PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		// PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		PRINT("---");
		for(--ite, --i, it = test.begin(); it != ite; --ite, --i)
			PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
	}
	{
		PRINT_BLU("\nft ")
		// ft::map<char,int> first; // --- default
		// first.new_node('a',21);
		// // --- operator[]
		// first['a']=10;
		// first['b']=30;
		// first['c']=50;
		// first['d']=70;
		// // --- range
		// std::map<char,int> second (first.begin(),first.end());
		// // --- copy
		// std::map<char,int> third (second);
		// // --- class as Compare
		// std::map<char,int,classcomp> fourth;
		// // --- function pointer as Compare
		// bool(*fn_pt)(char,char) = fncomp;
		// std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
		{
		ft::map<char,int> test;
		PRT("size :" << test.size() << "|");
		test['a'] = 7;		PRT(" " << test.size() << "|");
		test['c'] = 21;		PRT(" " << test.size() << "|");
		test['e'] = 42;		PRT(" " << test.size() << "|");
		test['b'] = 13;		PRT(" " << test.size() << "|");
		test['d'] = 26;		PRINT(" " << test.size() << "|");
		ft::map<char,int>::iterator		it = test.begin();
		ft::map<char,int>::iterator		ite = test.end();
		int i = 0;
		for(; it != ite; ++it, ++i)
			PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		// PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		PRINT("---");
		for(--ite, --i, it = test.begin(); it != ite; --ite, --i)
			PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		ENDL
		test.treeprint();
		}
		{
		ENDL
		PRINT_YLW("- balance -");
		// test.clear();
		ft::map<char,int> test;
		ft::map<char,int>::iterator		it, ite;
		PRT("size :" << test.size() << "|");
		test.insert(std::make_pair('a', 7));		PRT(" " << test.size() << "|");
		test.insert(std::make_pair('c',21));		PRT(" " << test.size() << "|");
		test.insert(std::make_pair('e',42));		PRT(" " << test.size() << "|");
		test.insert(std::make_pair('b',13));		PRT(" " << test.size() << "|");
		test.insert(std::make_pair('d',26));		PRINT(" " << test.size() << "|");
		it = test.begin();
		ite = test.end();
		int i = 0;
		for(; it != ite; ++it, ++i)
			PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		// PRINT(i << ": '"<< it->first << "'/" << it->second << "|");
		PRINT("---");
		for(--ite, --i, it = test.begin(); it != ite; --ite, --i)
			PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		PRINT(i << ": '"<< ite->first << "'/" << ite->second << "|");
		ENDL
		test.treeprint();
		}
		{
		PRINT_YLW("\n----Balance test advance----\n");
		ft::map<int, int> FT;
		std::map<int, int> STD;
		FT.insert(std::make_pair(1, 0));
		FT.insert(std::make_pair(10, 0));
		FT.insert(std::make_pair(20, 0));
		STD.insert(std::make_pair(1, 0));
		STD.insert(std::make_pair(10, 0));
		STD.insert(std::make_pair(20, 0));
		for (int i = 1; i <= 5; i += 1)
		{
			FT.insert(std::make_pair(-i, i));
			FT.insert(std::make_pair(i + 20, i));
			STD.insert(std::make_pair(-i, i));
			STD.insert(std::make_pair(i + 20, i));
		}
		FT.treeprint();
		PRINT_YLW("\n----FIND----\n");
		ft::map<int,int>::iterator		find_ft;
		std::map<int,int>::iterator		find_std;
		// S.erase(it);
		find_std = STD.find(-5);	PRINT("std: " << find_std->first);
		find_ft = FT.find(-5);	PRINT("ft : " << find_ft->first); ENDL
		find_std = STD.find(-2);	PRINT("std: " << find_std->first);
		find_ft = FT.find(-2);	PRINT("ft : " << find_ft->first); ENDL
		find_std = STD.find(25);	PRINT("std: " << find_std->first);
		find_ft = FT.find(25);	PRINT("ft : " << find_ft->first); ENDL
		find_std = STD.find(21);	PRINT("std: " << find_std->first);
		find_ft = FT.find(21);	PRINT("ft : " << find_ft->first); ENDL
		find_std = STD.find(10);	PRINT("std: " << find_std->first);
		find_ft = FT.find(10);	PRINT("ft : " << find_ft->first); ENDL
		// find_std = Z.find(99);	PRINT("std: " << find_std->first);
		// findS = S.find(99);	PRINT("ft : " << find_ft->first); ENDL
		PRINT_YLW("\n----CONST FIND----\n")
		ft::map<int,int>::const_iterator		const_find_ft;
		std::map<int,int>::const_iterator		const_find_std;
		const_find_ft = FT.find(-5);	PRINT("ft : " << const_find_ft->first);
		const_find_std = STD.find(-5);	PRINT("std: " << const_find_std->first); ENDL
		// const_find_std = 5; // no viable overloaded '='
		// const_find_ft = 5; // no viable overloaded '='
		PRINT_YLW("\n----ERASE----\n")
		// ft::map<int,int>::iterator		it, ite;
		FT.treeprint(); ENDL
		PRINT_BLU("Erase 23" );	FT.erase(23);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 0" );	FT.erase(0);	FT.treeprint(); ENDL
		PRINT_BLU("Erase -3" );	FT.erase(-3);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 20" );	FT.erase(20);	FT.treeprint(); ENDL
		PRINT_BLU("Erase -2" );	FT.erase(-2);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 1" );	FT.erase(1);	FT.treeprint(); ENDL
		PRINT_BLU("Erase -1" );	FT.erase(-1);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 22" );	FT.erase(22);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 24" );	FT.erase(24);	FT.treeprint(); ENDL
		PRINT_BLU("Erase -5" );	FT.erase(-5);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 21" );	FT.erase(21);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 25" );	FT.erase(25);	FT.treeprint(); ENDL
		PRINT_BLU("Erase -4" );	FT.erase(-4);	FT.treeprint(); ENDL
		PRINT_BLU("Erase 10" );	FT.erase(10);	FT.treeprint(); ENDL
		}
		{
		PRINT_YLW("\n----REVERSE ITERATOR----\n")
		ft::map<char,int>	mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		for(ft::map<char,int>::iterator it = mymap.begin(), ite = mymap.end(); it != ite; ++it)
			PRINT(it->first << ": "<< it->second);
		mymap.treeprint(); ENDL
		ft::map<char,int>::reverse_iterator		rit = mymap.rbegin();
		ft::map<char,int>::reverse_iterator		rite = mymap.rend();
		for(; rit != rite; ++rit)
			PRINT(rit->first << ": "<< rit->second);
		}
		{
		PRINT_YLW("\n----constructing maps----\n")
		ft::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		PRINT_BLU("ft []"); mymap.treeprint();

		PRINT_BLU("ft range"); 
		ft::map<char,int>	mymap_tmp(mymap.begin(),mymap.end());
		mymap_tmp.treeprint();

		PRINT_BLU("ft copy");
		ft::map<char,int>	mymap_third(mymap_tmp);
		mymap_third.treeprint();
		}
		{
		PRINT_YLW("\n----assignment operator with maps----\n")
		ft::map<char,int> first;
		ft::map<char,int> second;

		first['a']=10;
		first['b']=20;
		first['c']=30;
		first['d']=40;
		first['e']=50;
		first['f']=60;

		second = first;
		first = ft::map<char,int>();

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
		}
	}
}

void		iterators_map()
{
	PRINT_YLW("\n---| iterators_map | ---")
	PRINT_YLW("\n----map::begin/end----\n")
	{
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';
	}
	PRINT_YLW("\n----map::rbegin/rend----\n")
	{
	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
	}
}

void		capacity_map()
{
	PRINT_YLW("\n---| capacity_map | ---")
	PRINT_YLW("\n----// map::empty----\n")
	{
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
	}
	PRINT_YLW("\n----// map::size----\n")
	{
	ft::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	}
	PRINT_YLW("\n----// map::max_size----\n")
	{
	int i;
	ft::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";
	}
}

void		element_access_map()
{
	PRINT_YLW("\n---| element_access_map | ---")
	PRINT_YLW("\n----// accessing mapped values----\n")
	{
	ft::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}
}

void		modifiers_map()
{
	PRINT_YLW("\n---| modifiers_map | ---")
	PRINT_YLW("\n---- // map::insert (C++98) ----\n")
	{
	ft::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('b',300) );

	std::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('b',500) );
	if (ret.second==false) {
		std::cout << "element 'b' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('c',400));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('z',200));  // no max efficiency inserting

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.treeprint();
	}
	PRINT_YLW("\n---- // // swap maps ----\n")
	{
	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	foo.swap(bar); ENDL

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}
	PRINT_YLW("\n---- // map::clear ----\n")
	{
	std::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}
}

void		map_observers()
{
	PRINT_YLW("\n---| map_observers | ---")
	PRINT_YLW("\n---- // map::key_comp ----\n")
	{
	ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
	}
	PRINT_YLW("\n---- // map::value_comp ----\n")
	{
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	}
}

void		map_operations()
{
	PRINT_YLW("\n---| map_operations | ---")
	PRINT_YLW("\n---- // map::find ----\n")
	{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	PRINT_YLW("\n---- // map::count ----\n")
	{
	ft::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}
	}
	PRINT_YLW("\n---- // map::lower_bound/upper_bound ----\n")
	{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	mymap.erase('b');
	mymap.erase('c');
	mymap.erase('d');

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}
	PRINT_YLW("\n---- // map::equal_range ----\n")
	{
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
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
	find_std_func();
	find_func();
	count_func();
	map_base();
	iterators_map();
	capacity_map();
	element_access_map();
	modifiers_map();
	map_observers();
	map_operations();
	sleep(50);
	return 0;
}