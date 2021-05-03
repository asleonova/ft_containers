#include "List.hpp"
#include <memory>
#include <list>

int main()
{
    ft::list<int> a(5,100);
    std::list<int>::iterator it = a.begin();
    std::list<int>::iterator ite = a.end();
    while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }
    return 0;
}