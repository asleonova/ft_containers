#include "Vector.hpp"
#include "Iterator.hpp"

namespace ft
{
    template <bool Cond, typename T = void> struct enable_if {}

    template<typename T> struct enable_if<true, T> 
    {
        typedef T type;      
    }

}
