#include <memory>
#include <list>
#include <unistd.h>
#include <iostream>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

template <typename T>
void print_list(std::list<T> &lst)
{
	typename std::list<T>::iterator it = lst.begin();
	typename std::list<T>::iterator ite = lst.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

template <typename T>
void print_list_const(std::list<T> &lst)
{
	typename std::list<T>::const_iterator it = lst.begin();
	typename std::list<T>::const_iterator ite = lst.end();
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

	std::cout << green << "Testing empty list int: " << cend << std::endl;
	std::list<int> lst;
	//std::cout << "list size is: " << lst.size() << std::endl
			//  << std::endl;

	std::cout << blue << "***************[ Fill constructor test ]***************" << cend << std::endl;
	std::cout << green << "Testing list<int> lst1(10, 42): " << cend << std::endl;
	std::list<int> lst1(10, 42);
	print_list(lst1);
	std::cout << std::endl;

	/*std::cout << blue << "***************[ Range constructor test ]***************" << cend << std::endl;
	std::list<int> lst2;
	for (int i = 0; i < 10; ++i)
	{
		lst2.push_back(i);
	}
	std::list<int>::iterator it = lst2.begin();
	std::list<int>::iterator ite = lst2.end();
	std::list<int> lst3(it, ite);
	print_list(lst3);
	std::cout << std::endl;

	std::cout << blue << "***************[ Copy constructor test ]***************" << cend << std::endl;
	std::cout << green << "Making copy list<int> lst4(lst1): " << cend << std::endl;
	std::list<int>				lst4(lst1);
	print_list(lst4);


	std::cout << blue << "***************[ Operator = test ]***************" << cend << std::endl;
	std::cout << green << "Making list<int> lst5 = lst1: " << cend << std::endl;
	std::list<int>				lst5(10, 4);
	lst1 = lst5;
	print_list(lst1);
	std::cout << std::endl;
	*/
}

void iterator_test()
{
	std::cout << blue << "***************[ Iterators test (char) ]***************" << cend << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 10; ++i)
	{
		lst.push_back(i);
	}
	std::cout << green << "list contents, using iterator: " << cend << std::endl;
	print_list(lst);
	std::cout << green << "list contents in reverse, using the reverse iterator: " << cend << std::endl;

	/*std::list<int>::reverse_iterator rit = lst.rbegin();
	std::list<int>::reverse_iterator rite = lst.rend();

	while (rit != rite)
	{
		std::cout << *rit << " ";
		rit++;
	}
	std::cout << std::endl;
*/
	std::cout << green << "Testing arithmetic operations on iterator: " << cend << std::endl;
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	std::cout << "it value: " << *it << std::endl;
	it++;
	std::cout << "it++ value: " << *it << std::endl;
	it--;
	std::cout << "it-- value: " << *it << std::endl;
	++it;
	std::cout << "++it value: " << *it << std::endl;
	--it;
	std::cout << "--it value: " << *it << std::endl;

	/*std::cout << green << "Testing arithmetic operations on reverse iterator: " << cend << std::endl;
	std::list<int>::reverse_iterator itr = lst.rbegin();
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
	*/

	std::cout << green << "Testing iterator comparison: " << cend << std::endl;
	bool b = it == ite;
	std::cout << "it == ite: " << b << std::endl;
	b = it == it;
	std::cout << "it == it: " << b << std::endl;
	b = it != ite;
	std::cout << "it != ite: " << b << std::endl;
	b = ite != ite;
	std::cout << "ite != ite: " << b << std::endl;

	/*
	std::cout << green << "Testing reverse iterator comparison: " << cend << std::endl;
	bool r = rit == rite;
	std::cout << "rit == rite: " << r << std::endl;
	r = rit == rit;
	std::cout << "rit == rit: " << r << std::endl;
	r = rit != rite;
	std::cout << "rit != rite: " << r << std::endl;
	r = rite != rite;
	std::cout << "rite != rite: " << r << std::endl;
*/
	std::cout << std::endl;
}

void const_iterator_test()
{
	std::cout << blue << "***************[ Const iterators test (char) ]***************" << cend << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 10; ++i)
	{
		lst.push_back(i);
	}
	std::cout << green << "list contents, using iterator: " << cend << std::endl;
	print_list_const(lst);

	std::cout << green << "Testing iterator comparison: " << cend << std::endl;
	std::list<int>::const_iterator it = lst.begin();
	std::list<int>::const_iterator ite = lst.end();
	
	bool b = it == ite;
	std::cout << "it == ite: " << b << std::endl;
	b = it == it;
	std::cout << "it == it: " << b << std::endl;
	b = it != ite;
	std::cout << "it != ite: " << b << std::endl;
	b = ite != ite;
	std::cout << "ite != ite: " << b << std::endl;
}

int main()
{
	constructor_test();
	iterator_test();
	const_iterator_test();
    std::list<std::string> a;
    std::list<std::string> a1;
    std::list<std::string>::iterator it1 = a.begin();
    std::list<std::string>::iterator it3 = a1.begin();
    std::cout << "beg before: " << *it1 << std::endl;
    std::cout << "std:: " << *it3 << std::endl;
    a.push_back("fas");
    a.push_back("t");
    a.push_back("kfddffjd");
    std::list<std::string>::iterator it = a.begin();
    std::list<std::string>::iterator ite = a.end();
    while (it != ite)
    {
       std::cout << *it << std::endl;
        it++;
    }

    std::list<std::string>::iterator it2 = a.begin();
    std::cout << "astder ints: " << *it2 << std::endl;

    return 0;
}