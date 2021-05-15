// splicing lists
#include <iostream>
#include <list>

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

int main()
{
	std::list<int>				mylist1, mylist2;
	std::list<int>::iterator		it;
	std::list<int>::iterator		tmp;

	// Set some initial values
	for (int i = 1; i <= 4; ++i) 	// mylist1: 1 2 3 4
		mylist1.push_back(i);

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);	// mylist2: 10 20 30

	// Print initial lists
    std::cout << "mylist1 contents: " << std::endl;
	print_list(mylist1);
    std::cout << "mylist1 size: " << mylist1.size() << std::endl;

    std::cout << "mylist2 contents: " << std::endl;
    print_list(mylist2);
    std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	it = mylist1.begin();
	++it;							// points to 2


	std::cout << "\x1b[32m";
	std::cout << "SPLICE (entire list) mylist2 to mylist1 at the 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;
	mylist1.splice(it, mylist2);	// mylist1: 1 10 20 30 2 3 4
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
	it++;							// 'it' points now to 30
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

    return 0;
}