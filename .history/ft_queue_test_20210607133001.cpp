#include "Queue.hpp"
#include "Vector.hpp"
#include "List.hpp"
#include <deque>
#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <squeue>
#include <unistd.h>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define cend "\x1b[0m"

void contstructor_test()
{
    std::cout << blue << "***************[ Constructors test ]***************" << cend << std::endl;

    std::deque<char> mydeque(9, 'a'); // deque with 9 elements
    ft::vector<int> myvector(2, 200); // vector with 2 elements

    ft::squeue<int> first;          // empty squeue
    ft::squeue<int, ft::list <int> >mylist; // squeue initialized to copy of deque

    ft::squeue<int, ft::list <int> > second(mylist); // squeue initialized to copy of list

    ft::squeue<int, ft::vector<int> > third; // empty squeue using vector
    ft::squeue<int, ft::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << std::endl;
    std::cout << "size of second: " << second.size() << std::endl;
    std::cout << "size of third: " << third.size() << std::endl;
    std::cout << "size of fourth: " << fourth.size() << std::endl;
}

void empty_test()
{
    std::cout << blue << "***************[ empty() test ]***************" << cend << std::endl;

    ft::squeue<int> mysqueue_e;
    int sum(0);

    for (int i = 1; i <= 10; i++)
        mysqueue_e.push(i);

    while (!mysqueue_e.empty())
    {
        sum += mysqueue_e.top();
        mysqueue_e.pop();
    }

    std::cout << "total: " << sum << std::endl;
}

void size_test()
{
    std::cout << blue << "***************[ size() test ]***************" << cend << std::endl;

    ft::squeue<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i = 0; i < 5; i++)
        myints.push(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.pop();
    std::cout << "2. size: " << myints.size() << std::endl;
}

void top_push_test()
{
    std::cout << blue << "***************[ top & push test ]***************" << cend << std::endl;
    ft::squeue<int> mysqueue;

    mysqueue.push(10);
    mysqueue.push(20);

    mysqueue.top() -= 5;

    std::cout << "mysqueue.top() is now " << mysqueue.top() << std::endl;
}

void pop_test()
{
    std::cout << blue << "***************[ pop() test ]***************" << cend << std::endl;
    ft::squeue<int> mysqueue;

    for (int i = 0; i < 5; ++i)
        mysqueue.push(i);

    std::cout << "Popping out elements...";
    while (!mysqueue.empty())
    {
        std::cout << ' ' << mysqueue.top();
        mysqueue.pop();
    }
    std::cout << std::endl;
}

void relational_operators_test()
{
    ft::squeue<int> mysqueue;
    for (int i = 0; i < 10; ++i)
        mysqueue.push(i);
    ft::squeue<int> mysqueue1(mysqueue);

    bool b = mysqueue == mysqueue1;
    std::cout << "mysqueue == mysqueue1(true) : " << b << std::endl;
    b = mysqueue != mysqueue1;
    std::cout << "mysqueue != mysqueue1(false) : " << b << std::endl;
    mysqueue.pop();
    b = mysqueue < mysqueue1;
    std::cout << "mysqueue < mysqueue1(true) : " << b << std::endl;
    b = mysqueue > mysqueue1;
    std::cout << "mysqueue > mysqueue1(false) : " << b << std::endl;
    b = mysqueue <= mysqueue1;
    std::cout << "mysqueue <= mysqueue1(true) : " << b << std::endl;
    b = mysqueue >= mysqueue1;
    std::cout << "mysqueue >= mysqueue1(false) : " << b << std::endl;  
}

int main()
{
    contstructor_test();
    empty_test();
    size_test();
    top_push_test();
    pop_test();
    relational_operators_test();
  //  sleep(50);
    return 0;
}