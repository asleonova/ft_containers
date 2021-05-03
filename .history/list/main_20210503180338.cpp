#include "List.hpp"
#include <memory>

int main()
{
    ft::list<int> a(5,100);
    ft::list<int>::iterator it = a.begin();
    return 0;
}