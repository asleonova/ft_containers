#include <iostream>

bool gg(int x, int y)
{
    return x == y;
}

int main()
{
    std::cout << gg(5, 6) << std::endl;    
}