#include "Queue.hpp"
#include "Vector.hpp"
#include "List.hpp"
#include <deque>
#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>
#include <unistd.h>
#include <queue>

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

    ft::queue<int> first;          // empty queue
    ft::queue<int, ft::list <int> >mylist; // queue initialized to copy of deque

    ft::queue<int, ft::list <int> > second(mylist); // queue initialized to copy of list

    ft::queue<int, ft::vector<int> > third; // empty queue using vector
    ft::queue<int, ft::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << std::endl;
    std::cout << "size of second: " << second.size() << std::endl;
    std::cout << "size of third: " << third.size() << std::endl;
    std::cout << "size of fourth: " << fourth.size() << std::endl;
}

void empty_test()
{
    std::cout << blue << "***************[ empty() test ]***************" << cend << std::endl;

  ft::queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  while (!myqueue.empty())
  {
     sum += myqueue.front();
     myqueue.pop();
  }

  std::cout << "total: " << sum << '\n';
}

void size_test()
{
    std::cout << blue << "***************[ size() test ]***************" << cend << std::endl;

    ft::queue<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i = 0; i < 5; i++)
        myints.push(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.pop();
    std::cout << "2. size: " << myints.size() << std::endl;
}

void front_push_test()
{
    std::cout << blue << "***************[ front & push test ]***************" << cend << std::endl;
ft::queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << std::endl;

void pop_test()
{
    std::cout << blue << "***************[ pop() test ]***************" << cend << std::endl;
    ft::stack<int> mystack;

    for (int i = 0; i < 5; ++i)
        mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << std::endl;
}

void relational_operators_test()
{
    ft::stack<int> mystack;
    for (int i = 0; i < 10; ++i)
        mystack.push(i);
    ft::stack<int> mystack1(mystack);

    bool b = mystack == mystack1;
    std::cout << "mystack == mystack1(true) : " << b << std::endl;
    b = mystack != mystack1;
    std::cout << "mystack != mystack1(false) : " << b << std::endl;
    mystack.pop();
    b = mystack < mystack1;
    std::cout << "mystack < mystack1(true) : " << b << std::endl;
    b = mystack > mystack1;
    std::cout << "mystack > mystack1(false) : " << b << std::endl;
    b = mystack <= mystack1;
    std::cout << "mystack <= mystack1(true) : " << b << std::endl;
    b = mystack >= mystack1;
    std::cout << "mystack >= mystack1(false) : " << b << std::endl;  
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