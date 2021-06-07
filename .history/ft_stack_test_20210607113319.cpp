#include "Stack.hpp"
#include "Vector.hpp"
#include "List.hpp"
#include <deque>
#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>
#include <unistd.h>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

void contstructor_test()
{
    std::cout << blue << "***************[ Constructors test ]***************" << cend << std::endl;

    ft::list<int> mylist(3, 100);   // list with 3 elements
    ft::vector<int> myvector(2, 200); // vector with 2 elements

    ft::stack<int> first;           // empty stack
    ft::stack<int> second(mylist); // stack initialized to copy of list

    ft::stack<int, ft::vector<int> > third; // empty stack using vector
    ft::stack<int, ft::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << std::endl;
    std::cout << "size of second: " << second.size() << std::endl;
    std::cout << "size of third: " << third.size() << std::endl;
    std::cout << "size of fourth: " << fourth.size() << std::endl;
}

void empty_test()
{
    std::cout << blue << "***************[ empty() test ]***************" << cend << std::endl;

    ft::stack<int> mystack_e;
    int sum (0);

    for (int i=1;i<=10;i++) mystack_e.push(i);

    while (!mystack_e.empty())
    {
        sum += mystack_e.top();
        mystack_e.pop();
    }

    std::cout << "total: " << sum << std::endl;
}

void size_test()
{
    std::cout << blue << "***************[ size() test ]***************" << cend << std::endl;

    ft::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';

}

void 

int main()
{




    return 0;
}