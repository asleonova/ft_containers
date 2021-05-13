#include "List.hpp"
#include <memory>
#include <list>
#include <unistd.h>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

template <typename T>
void print_list(ft::list<T> &lst)
{
	typename ft::list<T>::iterator it = lst.begin();
	typename ft::list<T>::iterator ite = lst.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

template <typename T>
void print_list_const(ft::list<T> &lst)
{
	typename ft::list<T>::const_iterator it = lst.begin();
	typename ft::list<T>::const_iterator ite = lst.end();
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
	ft::list<int> lst;
	//std::cout << "list size is: " << lst.size() << std::endl
			//  << std::endl;

	std::cout << blue << "***************[ Fill constructor test ]***************" << cend << std::endl;
	std::cout << green << "Testing list<int> lst1(10, 42): " << cend << std::endl;
	ft::list<int> lst1(10, 42);
	print_list(lst1);
	std::cout << std::endl;

	/*std::cout << blue << "***************[ Range constructor test ]***************" << cend << std::endl;
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
	ft::list<int>				lst4(lst1);
	print_list(lst4);


	std::cout << blue << "***************[ Operator = test ]***************" << cend << std::endl;
	std::cout << green << "Making list<int> lst5 = lst1: " << cend << std::endl;
	ft::list<int>				lst5(10, 4);
	lst1 = lst5;
	print_list(lst1);
	std::cout << std::endl;
	*/
}

void iterator_test()
{
	std::cout << blue << "***************[ Iterators test (char) ]***************" << cend << std::endl;

	ft::list<int> lst;
	for (int i = 0; i < 10; ++i)
	{
		lst.push_back(i);
	}
	std::cout << green << "list contents, using iterator: " << cend << std::endl;
	print_list(lst);
	std::cout << green << "list contents in reverse, using the reverse iterator: " << cend << std::endl;

	ft::list<int>::reverse_iterator rit = lst.rbegin();
	ft::list<int>::reverse_iterator rite = lst.rend();

	while (rit != rite)
	{
		std::cout << *rit << " ";
		rit++;
	}
	std::cout << std::endl;
	std::cout << green << "Testing arithmetic operations on iterator: " << cend << std::endl;
	ft::list<int>::iterator it = lst.begin();
	ft::list<int>::iterator ite = lst.end();
	std::cout << "it value: " << *it << std::endl;
	it++;
	std::cout << "it++ value: " << *it << std::endl;
	it--;
	std::cout << "it-- value: " << *it << std::endl;
	++it;
	std::cout << "++it value: " << *it << std::endl;
	--it;
	std::cout << "--it value: " << *it << std::endl;

	std::cout << green << "Testing arithmetic operations on reverse iterator: " << cend << std::endl;
	ft::list<int>::reverse_iterator itr = lst.rbegin();
	std::cout << "itr value: " << *itr << std::endl;
	itr++;
	std::cout << "itr++ value: " << *itr << std::endl;
	itr--;
	std::cout << "itr-- value: " << *itr << std::endl;
	++itr;
	std::cout << "++itr value: " << *itr << std::endl;
	--itr;
	std::cout << "--itr value: " << *itr << std::endl;

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

	ft::list<int> lst;
	for (int i = 0; i < 10; ++i)
	{
		lst.push_back(i);
	}
	std::cout << green << "list contents, using iterator: " << cend << std::endl;
	print_list_const(lst);

	std::cout << green << "Testing iterator comparison: " << cend << std::endl;
	ft::list<int>::const_iterator it = lst.begin();
	ft::list<int>::const_iterator ite = lst.end();
	
	bool b = it == ite;
	std::cout << "it == ite: " << b << std::endl;
	b = it == it;
	std::cout << "it == it: " << b << std::endl;
	b = it != ite;
	std::cout << "it != ite: " << b << std::endl;
	b = ite != ite;
	std::cout << "ite != ite: " << b << std::endl;
}

void capacity_tests()
{
	std::cout << blue << "***************[ empty() test (int) ]***************" << cend << std::endl;
	ft::list<int> myints;
	std::cout << green << "Empty list: " << cend << std::endl;
	std::cout << "is_empty: " << myints.empty() << '\n';
	std::cout << "size: " << myints.size() << std::endl;

	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	std::cout << green << "After push_back 10 elements: " << cend << std::endl;
	std::cout << "is_empty: " << myints.empty() << '\n';
	std::cout << "size: " << myints.size() << std::endl;
	print_list(myints);
	/* myints.insert(myints.end(), 10, 100);
	std::cout << green << "After inserting 10 elements: " << cend << std::endl;
	std::cout << "2. size: " << myints.size() << '\n';
	*/
	myints.pop_back();
	std::cout << green << "After popback(): " << cend << std::endl;
	std::cout << "3. size: " << myints.size() << '\n' << '\n';
	print_list(myints);

	myints.push_front(8);
	std::cout << green << "After push_front(666): " << cend << std::endl;
	std::cout << "size: " << myints.size() << '\n' << '\n';
	std::cout << "list contents: " << std::endl;
	print_list(myints);
	
	myints.pop_front();
	std::cout << green << "After popfront(): " << cend << std::endl;
	std::cout << "4. size: " << myints.size() << std::endl;
	std::cout << "list contents: " << std::endl;
	print_list(myints);


	std::cout << blue << "***************[ max_size() and size() test (int) ]***************" << cend << std::endl;
	std::cout << green << "Taking the same vector: " << cend << std::endl;
	std::cout << "size: " << myints.size() << "\n";
	std::cout << "max_size: " << myints.max_size() << "\n" << "\n";


	std::cout << green << "insert range of elements int arr[] = {501,502,503} at the begin() + 1" << cend << "\n";
	int myarray[] = {501, 502, 503};
	ft::list<int>::iterator it2 = myints.begin();
	it2++;
	it2++;
	myints.insert(it2, myarray, myarray + 3);
	print_list(myints);
	std::cout << "list size: " << myints.size();
	std::cout << std::endl;



	std::cout << blue << "***************[ erase test (int) ]***************" << cend << std::endl;
	std::cout << green << "erase the first element: " << cend << "\n";
	myints.erase(myints.begin());
	print_list(myints);
	std::cout << "list size: " << myints.size() << std::endl;
	//std::cout << " | vector capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << green << "erase the first 3 elements: " << cend << "\n";
	ft::list<int>::iterator it = myints.begin();
	ft::list<int>::iterator ite = myints.begin()++;
	ite++;
	ite++;
	ite++;
	std::cout << *it << std::endl;
	std::cout << *ite << std::endl;
	myints.erase(myints.begin(), ite);
	print_list(myints);
	std::cout << "list size: " << myints.size();
	//std::cout << " | vector capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;
	myints.clear();
	std::cout << "size: " << myints.size() << std::endl;
	std::cout << "is_empty: " << myints.empty() << std::endl;

	
}

int main()
{
	constructor_test();
	iterator_test();
	const_iterator_test();
	capacity_tests();
    ft::list<std::string> a;
    std::list<std::string> a1;
    ft::list<std::string>::iterator it1 = a.begin();
    std::list<std::string>::iterator it3 = a1.begin();
    std::cout << "beg before: " << *it1 << std::endl;
    std::cout << "std:: " << *it3 << std::endl;
    a.push_back("fas");
    a.push_back("t");
    a.push_back("kfddffjd");
    ft::list<std::string>::iterator it = a.begin();
    ft::list<std::string>::iterator ite = a.end();
    while (it != ite)
    {
       std::cout << *it << std::endl;
        it++;
    }

    ft::list<std::string>::iterator it2 = a.begin();
    std::cout << "after ints: " << *it2 << std::endl;
	sleep(50);

    return 0;
}