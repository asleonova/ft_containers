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

template <class Key, class T>
void print_map_const(ft::map<Key, T> &map)
{
	typename ft::map<Key, T>::const_iterator cit = map.begin();
	typename ft::map<Key, T>::const_iterator cite = map.end();
	while (cit != cite)
	{
		std::cout << cit->first << " ," << cit->second << " | ";
		++cit;
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

	std::cout << green << "Map contents: " << cend << std::endl;
	print_map(first);
	ft::map<char,int> second;
	second = first;	
	// std::cout << green << "Testing range constructor: " << cend << std::endl;
  	// ft::map<char,int> second (first.begin(),first.end());
	std::cout << green << "Map contents: " << cend << std::endl;
	print_map(second);
	std::cout << green << "Testing copy constructor: " << cend << std::endl;
  	ft::map<char,int> third (second);
	std::cout << green << "Map contents (third): " << cend << std::endl;
	print_map(third);
	third = first;
	std::cout << green << "Testing operator = : " << cend << std::endl;
	std::cout << green << "Map contents (third): " << cend << std::endl;
	print_map(third);
  	ft::map<char,int,classcomp> fourth; // class as Compare
  	bool(*fn_pt)(char,char) = fncomp;
  	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
}

void iterator_test()
{
	std::cout << blue << "***************[ Iterators test (int) ]***************" << cend << std::endl;

	ft::map<int, int> map;
	map[1] = 1;
	map[3] = 3;
	map[6] = 6;
	map[2] = 2;
	map[4] = 4;
	map[5] = 5;
	std::cout << green << "map contents, using iterator: " << cend << std::endl;
	print_map(map);
	std::cout << green << "map contents in reverse, using the reverse iterator: " << cend << std::endl;

	ft::map<int, int>::reverse_iterator rit = map.rbegin();
	ft::map<int, int>::reverse_iterator rite = map.rend();

	while (rit != rite)
	{
		std::cout << rit->first << " " << rit->second << " | ";
		rit++;
	}
	std::cout << std::endl;
	std::cout << green << "Testing arithmetic operations on iterator: " << cend << std::endl;
	ft::map<int, int>::iterator it = map.begin();
	ft::map<int, int>::iterator ite = map.end();
	std::cout << "it value: " << it->first << std::endl;
	it++;
	std::cout << "it++ value: " << it->first << std::endl;
	it--;
	std::cout << "it-- value: " << it->first << std::endl;
	++it;
	std::cout << "++it value: " << it->first << std::endl;
	--it;
	std::cout << "--it value: " << it->first << std::endl;

	std::cout << green << "Testing arithmetic operations on reverse iterator: " << cend << std::endl;
	ft::map<int, int>::reverse_iterator itr = map.rbegin();
	std::cout << "itr value: " << itr->first << std::endl;
	itr++;
	std::cout << "itr++ value: " << itr->first << std::endl;
	itr--;
	std::cout << "itr-- value: " << itr->first << std::endl;
	++itr;
	std::cout << "++itr value: " << itr->first << std::endl;
	--itr;
	std::cout << "--itr value: " << itr->first << std::endl;

	std::cout << green << "Testing iterator comparison: " << cend << std::endl;
	bool b = it == ite;
	std::cout << "it == ite: " << b << std::endl;
	b = it == it;
	std::cout << "it == it: " << b << std::endl;
	b = it != ite;
	std::cout << "it != ite: " << b << std::endl;
	b = ite != ite;
	std::cout << "ite != ite: " << b << std::endl;

	std::cout << green << "Testing reverse iterator comparison: " << cend << std::endl;
	bool r = rit == rite;
	std::cout << "rit == rite: " << r << std::endl;
	r = rit == rit;
	std::cout << "rit == rit: " << r << std::endl;
	r = rit != rite;
	std::cout << "rit != rite: " << r << std::endl;
	r = rite != rite;
	std::cout << "rite != rite: " << r << std::endl;
	std::cout << std::endl;
}

void const_iterator_test()
{
	std::cout << blue << "***************[ Const iterators test (char) ]***************" << cend << std::endl;
	
	ft::map<int, int> map;
	map[1] = 1;
	map[3] = 3;
	map[6] = 6;
	map[2] = 2;
	map[4] = 4;
	map[5] = 5;
	std::cout << green << "map contents, using iterator: " << cend << std::endl;
	print_map_const(map);

	std::cout << green << "Testing iterator comparison: " << cend << std::endl;
	ft::map<int, int>::const_iterator cit = map.begin();
	ft::map<int, int>::const_iterator cite = map.end();

	bool b = cit == cite;
	std::cout << "cit == cite: " << b << std::endl;
	b = cit == cit;
	std::cout << "it == it: " << b << std::endl;
	b = cit != cite;
	std::cout << "cit != cite: " << b << std::endl;
	b = cite != cite;
	std::cout << "cite != cite: " << b << std::endl;
}

	void insert_test()
	{
		ft::map<int, int> mymap;
		ft::map<int, int>::iterator it;
		ft::map<int, int>:: iterator ite;

	
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
	std::cout << "ITER VALUE IS: " << it->first << std::endl;
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
	print_map(mymap);
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
	it = anothermap.begin();
	std::cout << "map begin: " << it->first << std::endl;
	std::cout << "map end: " << anothermap.end()->first << std::endl;
	std::cout << "IT value is: " << it->first << std::endl;
	anothermap.erase(1); // 1
	std::cout << "________________1_______________" << std::endl;
	std::cout << "IT value is: " << it->first << std::endl;
	anothermap.treeprint();
	anothermap.erase(2); // 2
		std::cout << "______________2__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(3); //3
			std::cout << "______________3__________________" << std::endl;
	anothermap.treeprint();	
	anothermap.erase(4); //4
			std::cout << "______________4__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(5);//5
			std::cout << "______________5__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(6);//6
			std::cout << "______________6__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(7); //7
			std::cout << "______________7__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(8); //8
			std::cout << "______________8__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(9); //9
			std::cout << "______________9__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(10); //10
			std::cout << "______________10__________________" << std::endl;
	anothermap.treeprint();
	anothermap.erase(17);
	std::cout << "______________17__________________" << std::endl;

	mymap.insert(std::pair<int, int>(3, 400));
	mymap.insert(std::pair<int, int>(2, 400));
	mymap.insert(std::pair<int, int>(1, 400));
	mymap.insert(std::pair<int, int>(8, 100));
	std::cout << "Contents of mymap: " << std::endl;
	print_map(mymap);
	anothermap.clear();
	std::cout << "mymap size is: " << anothermap.size() << std::endl;
	std::cout << "Inserting new elements : " << std::endl;
	mymap.insert(std::pair<int, int>(3, 400));
	mymap.insert(std::pair<int, int>(2, 400));
	mymap.insert(std::pair<int, int>(1, 400));
	mymap.insert(std::pair<int, int>(8, 100));
	std::cout << "Contents of mymap: " << std::endl;
	anothermap.erase(anothermap.begin(), anothermap.end());
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


	it = mymap.begin();
	it++;
	std::cout << "it calue is: " << it->first << std::endl;

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
	constructor_test();
	//erase_func_test();
	//find_std_func();
	//find_func();
	//count_func();
	sleep(50);
	return 0;
}