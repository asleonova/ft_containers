/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:06:11 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/26 14:28:54 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class list
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename ft::myIterator<pointer> iterator;
        typedef typename ft::myIterator<const_pointer> const_iterator;
        typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

        /*================================ 4 CONSTRUCTORS: ================================*/

        // #1 : DEFAULT:
        explicit list(const allocator_type &alloc = allocator_type()) {}

        // #2: FILL:
        explicit list(size_type n, const value_type &val = value_type(),
                      const allocator_type &alloc = allocator_type()) {}

        // #3: RANGE:
        template <class InputIterator>
        list(InputIterator first, InputIterator last,
             const allocator_type &alloc = allocator_type()){}

        // #4 COPY:
        list(const list &x){ *this = src}

        /*================================ DESTRUCTOR: ================================*/ 
        ~list() {}

    private:
        pointer _capacity;
        pointer _v_begin;
        pointer _v_end;
        allocator_type _allocator_type
    };
}