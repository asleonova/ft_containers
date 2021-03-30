#include <iostream>

bool gg(int x, int y)
{
    return x == y;
}

int main()
{
    std::cout << gg(8, 5) << std::endl;    
}