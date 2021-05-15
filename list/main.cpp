#include "List.hpp"
#include <memory>
#include <list>
#include <unistd.h>
#include <cmath>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"


// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// a binary predicate implemented as a function:
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

// a binary predicate implemented as a class:
struct is_near
{
	bool operator()(double first, double second)
	{
		return (fabs(first - second) < 5.0);
	}
};

// a predicate implemented as a function:
bool single_digit(const int &value) { return (value < 10); }

// a predicate implemented as a class:
struct is_odd
{
	bool operator()(const int &value) { return (value % 2) == 1; }
};

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
void print_list_reverse(ft::list<T> &lst)
{
	typename ft::list<T>::reverse_iterator rit = lst.begin();
	typename ft::list<T>::reverse_iterator rite = lst.end();
	while (rit != rite)
	{
		std::cout << *rit << " | ";
		rit++;
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
	std::cout << "list size is: " << lst.size() << std::endl
			  << std::endl;

	std::cout << blue << "***************[ Fill constructor test ]***************" << cend << std::endl;
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

	// std::cout << blue << "***************[ Operator = test ]***************" << cend << std::endl;
	// std::cout << green << "Making list<int> lst5 = lst1: " << cend << std::endl;
	// ft::list<int>				lst5(10, 4);
	// lst1 = lst5;
	// print_list(lst1);
	// std::cout << std::endl;
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
	std::cout << "3. size: " << myints.size() << '\n'
			  << '\n';
	print_list(myints);

	myints.push_front(666);
	std::cout << green << "After push_front(666): " << cend << std::endl;
	std::cout << "size: " << myints.size() << '\n'
			  << '\n';
	std::cout << "list contents: " << std::endl;
	for (int i = 0; i < 5; ++i)
		myints.push_front(i);

	ft::list<int>::reverse_iterator rit = myints.rbegin();
	ft::list<int>::reverse_iterator rite = myints.rend();
	std::cout << "Printing in reverse order: " << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << " ";
		rit++;
	}

	myints.pop_front();
	std::cout << green << "After popfront(): " << cend << std::endl;
	std::cout << "4. size: " << myints.size() << std::endl;
	std::cout << "list contents: " << std::endl;
	print_list(myints);

	std::cout << blue << "***************[ max_size() and size() test (int) ]***************" << cend << std::endl;
	std::cout << green << "Taking the same list: " << cend << std::endl;
	std::cout << "size: " << myints.size() << "\n";
	std::cout << "max_size: " << myints.max_size() << "\n"
			  << "\n";

	std::cout << green << "insert range of elements int arr[] = {501,502,503} at the begin() + 1" << cend << "\n";
	int myarray[] = {501, 502, 503};
	ft::list<int>::iterator it2 = myints.begin();
	it2++;
	it2++;
	myints.insert(it2, myarray, myarray + 3);
	print_list(myints);
	std::cout << "list size: " << myints.size();
	std::cout << std::endl;

	std::cout << blue << "***************[ resize() test (int) ]***************" << cend << std::endl;
	myints.resize(5);
	std::cout << green << "myints.resize(5): " << cend << std::endl;
	print_list(myints);
	std::cout << green << "myints.resize(8, 100): " << cend << std::endl;
	myints.resize(8, 100);
	print_list(myints);
	myints.resize(12);
	std::cout << green << "myints.resize(12): " << cend << std::endl;
	print_list(myints);
	std::cout << '\n';

	std::cout << blue << "***************[ erase test (int) ]***************" << cend << std::endl;
	std::cout << green << "erase the first element: " << cend << "\n";
	myints.erase(myints.begin());
	print_list(myints);
	std::cout << "list size: " << myints.size() << std::endl;
	//std::cout << " | list capacity: " << vi.capacity() << std::endl;
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
	//std::cout << " | list capacity: " << vi.capacity() << std::endl;
	std::cout << std::endl;
	myints.clear();
	std::cout << "size: " << myints.size() << std::endl;
	std::cout << "is_empty: " << myints.empty() << std::endl;
}

void modifiers_test()
{
	std::cout << blue << "***************[ assign() test (int) ]***************" << cend << std::endl;
	ft::list<int> first;
	ft::list<int> second;
	ft::list<int> third;

	std::cout << green << "assign 7 ints with the value of 100 " << cend << "\n";
	first.assign(7, 100); // 7 ints with a value of 100
	std::cout << "list contents: " << std::endl;
	print_list(first);

	ft::list<int>::iterator it;
	it = first.begin()++;
	std::cout << green << "assign 5 central values of first" << cend << "\n";
	second.assign(it, first.end()--); // the 5 central values of first
	std::cout << "list contents: " << std::endl;
	print_list(second);

	std::cout << green << "creating array of ints {1776, 7, 4} and assigning from it: " << cend << "\n";
	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3); // assigning from array.
	std::cout << "list contents: " << std::endl;
	print_list(third);

	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
	std::cout << "Size of third: " << int(third.size()) << '\n'
			  << '\n';

	std::cout << blue << "***************[ push_back() and pop_back() test (float) ]***************" << cend << std::endl;
	ft::list<float> vf;
	vf.push_back(1.23f);
	vf.push_back(2.34f);
	vf.push_back(3.45f);
	vf.push_back(4.55f);
	vf.push_back(5.56f);
	std::cout << "list contents: " << std::endl;
	print_list(vf);

	std::cout << green << "calling pop_back() 2 times: " << cend << "\n";
	vf.pop_back();
	vf.pop_back();

	std::cout << "list contents: " << std::endl;
	print_list(vf);

	std::cout << blue << "***************[ insert test (int) ]***************" << cend << std::endl;
	ft::list<int> vi;
	for (int i = 0; i < 10; ++i)
		vi.push_back(i);
	std::cout << "list contents: " << std::endl;
	print_list(vi);
	std::cout << green << "insert 1 element at 2nd position with the value of 666 " << cend << "\n";
	it = vi.begin();
	it++;
	it++;
	vi.insert(it, 666);
	std::cout << "list contents: " << std::endl;
	print_list(vi);
	std::cout << "list size: " << vi.size();
	std::cout << std::endl;

	std::cout << green << "insert 5 element at 5th position with the value of 55 " << cend << "\n";

	vi.insert(it, 5, 55);
	std::cout << "list contents: " << std::endl;
	print_list(vi);
	std::cout << "list size: " << vi.size();
	std::cout << std::endl;

	std::cout << green << "insert range of elements int arr[] = {501,502,503} at the begin() + 1" << cend << "\n";
	int myarray[] = {501, 502, 503};
	vi.insert(vi.begin()++, myarray, myarray + 3);
	print_list(vi);
	std::cout << "list size: " << vi.size();
	std::cout << std::endl;

	std::cout << blue << "***************[ erase test (int) ]***************" << cend << std::endl;
	std::cout << green << "erase the 6th element: " << cend << "\n";
	vi.erase(vi.begin()++);
	print_list(vi);
	std::cout << "list size: " << vi.size();
	std::cout << std::endl;
	std::cout << green << "erase the first 3 elements: " << cend << "\n";
	vi.erase(vi.begin(), vi.begin()++);
	print_list(vi);
	std::cout << "list size: " << vi.size();
	std::cout << std::endl;

	std::cout << blue << "***************[ swap() test (string) ]***************" << cend << std::endl;
	ft::list<std::string> vs1;
	ft::list<std::string> vs2;
	vs1.push_back("chto");
	vs1.push_back("kak");
	vs1.push_back("sunshine");
	vs1.push_back("?");

	vs2.push_back("prosto");
	vs2.push_back("sdelai");
	vs2.push_back("it");

	std::cout << "list vs1 contents: " << std::endl;
	print_list(vs1);
	std::cout << "list vs2 contents: " << std::endl;
	print_list(vs2);

	std::cout << green << "after swapping values : " << cend << "\n";

	vs1.swap(vs2);

	std::cout << "list vs1 contents: " << std::endl;
	print_list(vs1);
	std::cout << "list vs2 contents: " << std::endl;
	print_list(vs2);

	std::cout << blue << "***************[ clear() test (string) ]***************" << cend << std::endl;
	std::cout << green << "Initial list contents : " << cend << "\n";
	print_list(vs1);
	std::cout << "list size: " << vs1.size();
	std::cout << std::endl;

	std::cout << green << "list contents after clear() : " << cend << "\n";
	vs1.clear();
	print_list(vs1);
	std::cout << "list size: " << vs1.size();
	std::cout << std::endl;
}

void splice_test()
{
	std::cout << blue << "***************[ splice() test (int) ]***************" << cend << std::endl;
	ft::list<int> mylist1, mylist2;
	ft::list<int>::iterator it;
	ft::list<int>::iterator tmp;

	// Set some initial values
	for (int i = 1; i <= 4; ++i) // mylist1: 1 2 3 4
		mylist1.push_back(i);

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10); // mylist2: 10 20 30

	// Print initial lists
	std::cout << "mylist1 contents: " << std::endl;
	print_list(mylist1);
	std::cout << "mylist1 size: " << mylist1.size() << std::endl;

	std::cout << "mylist2 contents: " << std::endl;
	print_list(mylist2);
	std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	it = mylist1.begin();
	++it; // points to 2

	std::cout << "\x1b[32m";
	std::cout << "SPLICE (entire list) mylist2 to mylist1 at the 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;
	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
								 // mylist2 (empty)
								 // 'it' still points to 2 (the 5th element)
	// Print lists after splicing
	std::cout << "\x1b[33m";
	std::cout << "'it' still points to: ";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << *it << std::endl;

	tmp = it; // Save it
	std::cout << "\x1b[33m";
	std::cout << "mylist1 after splicing mylist2 to it at 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;

	print_list(mylist1);
	std::cout << "mylist1 size: " << mylist1.size() << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "mylist2 after being spliced to mylist1 at 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;

	print_list(mylist2);
	std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	it = tmp; // Recover it

	std::cout << "\x1b[32m";
	std::cout << "SPLICE (single) mylist2 to mylist1 at the 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;
	mylist2.splice(mylist2.begin(), mylist1, it);
	// mylist1: 1 10 20 30 3 4
	// mylist2: 2
	// 'it' is now invalid.
	// Print lists after splicing
	std::cout << "\x1b[33m";
	std::cout << "'it' is invalid now"; // TEST in ORIGINAL!!!
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << *it << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "mylist1 after splicing";
	std::cout << "\033[0m\t\t" << std::endl;

	print_list(mylist1);
	std::cout << "mylist1 size: " << mylist1.size() << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "mylist2 after splicing";
	std::cout << "\033[0m\t\t" << std::endl;

	print_list(mylist2);
	std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	it = mylist1.begin();
	it++;
	it++;
	it++;									 // 'it' points now to 30
	std::cout << "IT: " << *it << std::endl; // test

	std::cout << "\x1b[32m";
	std::cout << "SPLICE (elem range) mylist1 3 last elements to the begining:";
	std::cout << "\033[0m\t\t" << std::endl;
	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
	// mylist1: 30 3 4 1 10 20

	std::cout << "mylist1 contains: ";
	print_list(mylist1);
	std::cout << "mylist1 size: " << mylist1.size() << std::endl;

	std::cout << "mylist2 contains: ";
	print_list(mylist2);
	std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	std::cout << std::endl;
}

void remove_test()
{
	std::cout << blue << "***************[ remove() test (int) ]***************" << cend << std::endl;
	std::cout << blue << "***************[ remove() test (int) ]***************" << cend << std::endl;
	int myints[] = {17, 89, 7, 14};
	ft::list<int> mylist(myints, myints + 4);
	std::cout << "mylist contents before removing: " << std::endl;
	print_list(mylist);
	std::cout << "list size before removing: " << mylist.size() << std::endl;
	mylist.remove(89);

	std::cout << "mylist contains: " << std::endl;
	print_list(mylist);
	std::cout << "list size: " << mylist.size() << std::endl;
}

void remove_if_test()
{
	std::cout << blue << "***************[ remove_if() test (int) ]***************" << cend << std::endl;
	int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
	ft::list<int> mylist(myints, myints + 8); // 15 36 7 17 20 39 4 1

	mylist.remove_if(single_digit); // 15 36 17 20 39

	mylist.remove_if(is_odd()); // 36 20

	std::cout << "mylist contains: ";
	print_list(mylist);
}

void unique_test()
{
	std::cout << blue << "***************[ unique() test (int) ]***************" << cend << std::endl;
	double mydoubles[] = { 0.0, 2.72,  3.14, 12.15, 12.77, 12.77,
						  15.3,  72.25, 72.25, 73.0,  73.35};
	ft::list<double> mylist(mydoubles, mydoubles + 10);
	std::cout << "list before unique func: " << std::endl;
	print_list(mylist);
	//mylist.sort(); //  2.72,  3.14, 12.15, 12.77, 12.77,
				   // 15.3,  72.25, 72.25, 73.0,  73.35

	mylist.unique(); //  2.72,  3.14, 12.15, 12.77
					 // 15.3,  72.25, 73.0,  73.35
	std::cout << "mylist contains: ";
	print_list(mylist);

	mylist.unique(same_integral_part); //  2.72,  3.14, 12.15
									   // 15.3,  72.25, 73.0

	std::cout << "mylist contains: ";
	print_list(mylist);

	mylist.unique(is_near()); //  2.72, 12.15, 72.25

	std::cout << "mylist contains: ";
	print_list(mylist);
}

int main()
{

	constructor_test();
	iterator_test();
	const_iterator_test();
	capacity_tests();
	modifiers_test();
	splice_test();
	remove_test();
	remove_if_test();
	unique_test();
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