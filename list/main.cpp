#include "List.hpp"
#include <memory>
#include <list>

int main()
{
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

    return 0;
}