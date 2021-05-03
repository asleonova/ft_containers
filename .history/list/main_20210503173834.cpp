#include "List.hpp"
#include <memory>

int main()
{
    ft::list<int> a(5,100);
    for (int i = 0; i < 4; ++i)
        std::cout << a << std::endl;
    return 0;
}