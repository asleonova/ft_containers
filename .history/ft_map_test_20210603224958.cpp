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

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

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

	std::cout << green << "Testing map <char, int> with some values added: " << cend << std::endl;

	ft::map<char,int> first;

 	first['a']=10;
  	first['b']=30;
  	first['c']=50;
  	first['d']=70;

	std::cout << green << "Testing range constructor: " << cend << std::endl;
  	ft::map<char,int> second (first.begin(),first.end());

	std::cout << green << "Testing copy constructor: " << cend << std::endl;
  	ft::map<char,int> third (second);
	std::cout << green << "Map contents (first): " << cend << std::endl;
	print_map(first);

  	ft::map<char,int,classcomp> fourth; // class as Compare

  	bool(*fn_pt)(char,char) = fncomp;
  	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare


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
}

void insert_test()
{
	
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
	sleep(50);
	return 0;
}