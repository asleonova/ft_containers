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

int main()
{
    std::deque<int> mydeque(3, 100);   // deque with 3 elements
    ft::vector<int> myvector(2, 200); // vector with 2 elements

    std::stack<int> first;           // empty stack
    std::stack<int> second(mydeque); // stack initialized to copy of deque

    std::stack<int, std::vector<int> > third; // empty stack using vector
    std::stack<int, std::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';
    return 0;
}