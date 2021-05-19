/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:29 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/19 17:30:34 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "Algorithm.hpp"
#include "Identifiers.hpp"

namespace ft
{
    template <class Key, class T,
              class Compare = less<Key>,
              class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        //typedef typename ft::ListIterator<pointer, Node> iterator;
        //typedef typename ft::ListIterator<const_pointer, Node> const_iterator;
        //typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        //typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

        /*================================ 4 CONSTRUCTORS: ================================*/

        /*================================ DESTRUCTOR: ================================*/

        /*================================ OPERATOR=: ================================*/

        /*================================ ITERATORS: ================================*/

        /*================================ CAPACITY: ================================*/

        /*================================ ELEMENT ACCESS: ================================*/

        /*================================ MODIFIERS: ================================*/




    };

}

#endif