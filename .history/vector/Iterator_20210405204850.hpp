/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:03 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/05 20:48:50 by dbliss           ###   ########.fr       */
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
    struct input_iterator_tag
    {
    };
    struct forward_iterator_tag : input_iterator_tag
    {
    };
    struct bidirectional_iterator_tag : forward_iterator_tag
    {
    };
    struct random_access_iterator_tag : bidirectional_iterator_tag
    {
    };
    struct output_iterator_tag
    {
    };

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
    struct iterator
    {
        typedef T value_type;               // Type of elements pointed by the iterator.
        typedef Distance difference_type;   // Type to represent the difference between two iterators.
        typedef Pointer pointer;            // Type to represent a pointer to an element pointed by the iterator.
        typedef Reference reference;        // Type to represent a reference to an element pointed by the iterator.
        typedef Category iterator_category; // Category to which the iterator belongs to. It must be one of the following iterator tags:
        // input_iterator_tag; output_iterator_tag; forward_iterator_tag; bidireational_iterator_tag; random_access_iterator_tag; random_access_iterator_tag;
    };

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T *>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template <class T>
    class myIterator : public ft::iterator<ft::random_access_iterator_tag, T> // нужно конечно же будет изменить для каждого типа!!! когда сделаю assign
    {
    private:
        typedef typename ft::iterator_traits<T> iterator_traits;
        T _ptr;

    public:
        typedef typename iterator_traits::iterator_category iterator_category;
        typedef typename iterator_traits::value_type value_type;
        typedef typename iterator_traits::difference_type difference_type;
        typedef typename iterator_traits::reference reference;
        typedef typename iterator_traits::pointer pointer;

        myIterator() : _ptr(NULL) {} // default
                                     // iterator(T ptr) : _ptr(ptr) {} //param constructor (for iterator init: begin, end, etc)
        myIterator(const T &ptr) : _ptr(ptr) {}
        myIterator(myIterator const &src) // copy constructor
        {
            *this = src;
        }

        myIterator &operator=(myIterator const &rhs) // asignment operator
        {
            this->_ptr = rhs._ptr;
            return (*this);
        }
        ~myIterator() {} // destructor

        // Comparison operations:

        bool &operator==(myIterator const &rhs) { return this->_ptr == rhs._ptr; }
        bool &operator!=(myIterator const &rhs) { return this->_ptr != rhs._ptr; }

        // Dereferensing operations as an rvalue:

        const T &operator*() const { return *(this->_ptr); }
        const T *operator->() const { return this->_ptr; }

        // Dereferencing operations as an lvalue (only for non-constant iterators)
        // TO DO: потому что так я не поняла, как реализовывать

        // Incrementing operations

        myIterator &operator++() // ++a
        {
            this->_ptr++;
            return (*this);
        }

        myIterator operator++(int) //a++
        {
            myIterator copy(*this);
            this->_ptr++;
            return (copy);
        }

        // TO DO:
        // вот это тоже не поняла на самом деле: "Two myIterators that compare equal, keep comparing equal after being both increased." *a++"

        // Decrementing operations:

        myIterator &operator--() //--a
        {
            this->_ptr--;
            return (*this);
        }
        myIterator &operator--(int) // a--
        {
            myIterator copy;
            this->_ptr--;
            return (*this);
        }

        // Arithmetic operations + -

        myIterator &operator+(size_t n) const // between an myIterator and int value
        {
            myIterator copy = *this;
            copy._ptr += n;
            return (copy);
        }

        myIterator &operator-(size_t n) const // between an myIterator and int value
        {
            myIterator copy = *this;
            copy._ptr -= n;
            return (copy);
        }
        myIterator &operator+(myIterator const &rhs) const // between myIterator and myIterator
        {
            return (this->_ptr + rhs._ptr);
        }
        myIterator &operator-(myIterator const &rhs) const // between myIterator and myIterator
        {
            return (this->_ptr - rhs._ptr);
        }
        // Inequality relational operators (< , > , <= and >=)
        bool operator>(myIterator const &rhs) { return this->_ptr > rhs._ptr; }
        bool operator>=(myIterator const &rhs) { return this->ptr >= rhs._ptr; }
        bool operator<(myIterator const &rhs) { return this->ptr < rhs._ptr; }
        bool operator<=(myIterator const &rhs) { return this->ptr <= rhs._ptr; }

        // Compound assignment operations += and -=
        myIterator &operator+=(size_t n)
        {
            this->_ptr += n;
            return (*this);
        }

        myIterator &operator-=(size_t n)
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