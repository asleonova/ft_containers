/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:03 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/05 16:13:39 by dbliss           ###   ########.fr       */
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

    struct output_iterator_tag
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

    template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T *, typename Reference = T &>
    struct iterator
    {
    public:
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    template <typename Iterator>
    struct iterator_traits
    {
    public:
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };

    template <typename T>
    struct iterator_traits<T *>
    {
    public:
        typedef random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
    };

    template <typename T>
    struct iterator_traits<const T *>
    {
    public:
        typedef random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
    };

    template <typename Iterator>
    Iterator
    next(Iterator iterator, unsigned long n = 1)
    {
        while (n--)
            ++iterator;
        return (iterator);
    }

    template <typename Iterator>
    Iterator
    prev(Iterator iterator, unsigned long n = 1)
    {
        while (n--)
            --iterator;
        return (iterator);
    }

    template <class It>
    typename ft::iterator_traits<It>::difference_type
    do_distance(It first, It last, ft::input_iterator_tag)
    {
        typename ft::iterator_traits<It>::difference_type result = 0;

        while (first != last)
        {
            ++first;
            ++result;
        }

        return (result);
    }

    template <class It>
    typename ft::iterator_traits<It>::difference_type
    do_distance(It first, It last, ft::random_access_iterator_tag)
    {
        return (last - first);
    }

    template <class It>
    typename ft::iterator_traits<It>::difference_type
    distance(It first, It last)
    {
        return do_distance(first, last, typename ft::iterator_traits<It>::iterator_category());
    }

    template <class T>
    class iterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {

    private:
        typedef typename ft::iterator_traits<T> traits;

    public:
        typedef typename traits::iterator_category iterator_category;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::reference reference;
        typedef typename traits::pointer pointer;

    private:
        T _ptr;

    public:
        iterator() : _ptr(NULL) {} // default
                                   // iterator(T ptr) : _ptr(ptr) {} //param constructor (for iterator init: begin, end, etc)
        explicit iterator(const T &ptr) : _ptr(ptr) {}
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