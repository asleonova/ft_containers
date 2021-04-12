/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:03 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/05 17:16:51 by dbliss           ###   ########.fr       */
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

    template <class T>
    class iterator
    {

    private:
        T _ptr;

    public:
        iterator() : _ptr(NULL) {} // default
                                   // iterator(T ptr) : _ptr(ptr) {} //param constructor (for iterator init: begin, end, etc)
        iterator(const T &ptr) : _ptr(ptr) {}
        iterator(iterator const &src) // copy constructor
        {
            *this = src;
        }

        iterator &operator=(iterator const &rhs) // asignment operator
        {
            this->_ptr = rhs._ptr;
            return (*this);
        }
        ~iterator() {} // destructor

        // Comparison operations:

        bool &operator==(iterator const &rhs) { return this->_ptr == rhs._ptr; }
        bool &operator!=(iterator const &rhs) { return this->_ptr != rhs._ptr; }

        // Dereferensing operations as an rvalue:

        const T &operator*() const { return *(this->_ptr); }
        const T *operator->() const { return this->_ptr; }

        // Dereferencing operations as an lvalue (only for non-constant iterators)
        // TO DO: потому что так я не поняла, как реализовывать

        // Incrementing operations

        iterator &operator++() // ++a
        {
            this->_ptr++;
            return (*this);
        }

        iterator &operator++(int) //a++
        {
            iterator copy = *this;
            this->_ptr++;
            return (copy);
        }

        // TO DO:
        // вот это тоже не поняла на самом деле: "Two iterators that compare equal, keep comparing equal after being both increased." *a++"

        // Decrementing operations:

        iterator &operator--() //--a
        {
            this->_ptr--;
            return (*this);
        }
        iterator &operator--(int) // a--
        {
            iterator copy;
            this->_ptr--;
            return (*this);
        }

        // Arithmetic operations + -

        iterator &operator+(size_t n) const // between an iterator and int value
        {
            iterator copy = *this;
            copy._ptr += n;
            return (copy);
        }

        iterator &operator-(size_t n) const // between an iterator and int value
        {
            iterator copy = *this;
            copy._ptr -= n;
            return (copy);
        }
        iterator &operator+(iterator const &rhs) const // between iterator and iterator
        {
            return (this->_ptr + rhs._ptr);
        }
        iterator &operator-(iterator const &rhs) const // between iterator and iterator
        {
            return (this->_ptr - rhs._ptr);
        }
        // Inequality relational operators (< , > , <= and >=)
        bool operator>(iterator const &rhs) { return this->_ptr > rhs._ptr; }
        bool operator>=(iterator const &rhs) { return this->ptr >= rhs._ptr; }
        bool operator<(iterator const &rhs) { return this->ptr < rhs._ptr; }
        bool operator<=(iterator const &rhs) { return this->ptr <= rhs._ptr; }

        // Compound assignment operations += and -=
        iterator &operator+=(size_t n)
        {
            this->_ptr += n;
            return (*this);
        }

        iterator &operator-=(size_t n)
        {
            this->_ptr -= n;
            return (*this);
        }

        // Offset dereference operator []
        T &operator[](size_t n) const
        {
            return *(*this + n);
        }
    };
}

#endif