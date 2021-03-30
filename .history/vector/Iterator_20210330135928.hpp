/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:03 by dbliss            #+#    #+#             */
/*   Updated: 2021/03/30 13:59:28 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Vector.hpp"

/*
     iterator synopsis

namespace ft
{
    template <typename T>
    class iterator
    {
        public:

            iterator(); //default
            iterator(iterator const &src); // copy constructor
            iterator &operator=(iterator const &rhs); // asignment operator
            ~iterator(); // destructor

            // Comparison operations:

            bool &operator==(iterator const &rhs);
            bool &operator!=(iterator const &rhs);

            // Dereferensing operations as an rvalue:

            const T &operator*() const;
            const T* operator->() const;

            // Dereferencing operations as an lvalue (only for non-constant iterators)
            // TO DO: потому что так я не поняла, как реализовывать

            // Incrementing operations

            iterator &operator++(); // ++a
            iterator  operator++(int); // a++


            // TO DO:
            // вот это тоже не поняла на самом деле: "Two iterators that compare equal, keep comparing equal after being both increased." *a++"

            // Decrementing operations:

            iterator &operator--(); //--a
            iterator operator--(int); // a--
            

            // Arithmetic operations + -

            iterator operator+(size_t n) const; // between an iterator and int value 
            iterator operator-(size_t n) const; // between an iterator and int value
            iterator operator+(iterator const &rhs) const; // between iterator and iterator
            iterator operator-(iterator const &rhs) const; // between iterator and iterator
            
            // Inequality relational operators (< , > , <= and >=)
            bool operator>(iterator const &rhs);
            bool operator>=(iterator const &rhs);
            bool operator<(iterator const &rhs);
            bool operator<=(iterator const &rhs);

            // Compound assignment operations += and -=
            iterator& operator+=(size_t n);
            iterator& operator-=(size_t n);


            // Offset dereference operator [] 
            T &operator[](size_t n) const;
    };
}

*/

namespace ft
{
    template <typename T>
    class iterator
    {
    
    private:


    public:
        iterator();                               //default
        iterator(iterator const &src);            // copy constructor
        iterator &operator=(iterator const &rhs); // asignment operator
        ~iterator();                              // destructor

        // Comparison operations:

        bool &operator==(iterator const &rhs);
        bool &operator!=(iterator const &rhs);

        // Dereferensing operations as an rvalue:

        const T &operator*() const;
        const T *operator->() const;

        // Dereferencing operations as an lvalue (only for non-constant iterators)
        // TO DO: потому что так я не поняла, как реализовывать

        // Incrementing operations

        iterator &operator++();   // ++a
        iterator operator++(int); // a++

        // TO DO:
        // вот это тоже не поняла на самом деле: "Two iterators that compare equal, keep comparing equal after being both increased." *a++"

        // Decrementing operations:

        iterator &operator--();   //--a
        iterator operator--(int); // a--

        // Arithmetic operations + -

        iterator operator+(size_t n) const;            // between an iterator and int value
        iterator operator-(size_t n) const;            // between an iterator and int value
        iterator operator+(iterator const &rhs) const; // between iterator and iterator
        iterator operator-(iterator const &rhs) const; // between iterator and iterator

        // Inequality relational operators (< , > , <= and >=)
        bool operator>(iterator const &rhs);
        bool operator>=(iterator const &rhs);
        bool operator<(iterator const &rhs);
        bool operator<=(iterator const &rhs);

        // Compound assignment operations += and -=
        iterator &operator+=(size_t n);
        iterator &operator-=(size_t n);

        // Offset dereference operator []
        T &operator[](size_t n) const;
    };
}

#endif