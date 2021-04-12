/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:03 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/12 13:14:26 by dbliss           ###   ########.fr       */
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
        T _ptr;

    public:
        typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<T>::value_type value_type;
        typedef typename ft::iterator_traits<T>::difference_type difference_type;
        typedef typename ft::iterator_traits<T>::reference reference;
        typedef typename ft::iterator_traits<T>::pointer pointer;

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

    template <class Iterator>
    class myReverse_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category, \
            typename ft::iterator_traits<Iterator>::value_type, typename ft::iterator_traits<Iterator>::difference_type, \
            typename ft::iterator_traits<Iterator>::pointer, typename ft::iterator_traits<Iterator>::reference>
    {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;

        myReverse_iterator() {}                                        // default
        explicit myReverse_iterator(iterator_type type) : _type(type) {} // initialization constructor
        template <class Iter>
        myReverse_iterator(const myReverse_iterator<Iter> &rev_type) : _type(rev_type._type) {}

        iterator_type base() const // returns a copy of the base iterator
        {
            return (_type);
        }

        reference operator*() const // Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it.
        {
            iterator_type base_copy = this->_type;
            return *(--base_copy);
        }

        myReverse_iterator operator+(difference_type n) const // Internally, the function applies the binary operator- on the base iterator and returns a reverse iterator constructed with the resulting iterator value.
        {
            return myReverse_iterator(this->_type - n);
        }

        myReverse_iterator &operator++() // Internally, the pre-increment version (1) decrements the base iterator kept by the object (as if applying operator-- to it).
        {
            this->_type--;
            return (*this);
        }

        myReverse_iterator operator++(int)
        {
            myReverse_iterator base_copy(*this);
            this->_type--;
            return (base_copy);
        }

        myReverse_iterator &operator+=(difference_type n) // Internally, the function decreases by n the base iterator kept by the object (as if applying operator-= to it)
        {
            this->_type -= n;
            return (*this);
        }

        myReverse_iterator operator-(difference_type n) const
        {
            return myReverse_iterator(this->_type + n);
        }

        myReverse_iterator &operator--()
        {
            this->_type++;
            return (*this);
        }

        myReverse_iterator operator--(int)
        {
            myReverse_iterator base_copy(*this);
            this->type++;
            return (base_copy);
        }

        myReverse_iterator& operator-=(difference_type n)
        {
            this->_type += n;
            return (*this); 
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        reference operator[] (difference_type n) const // Internally, the function accesses the proper element of its base iterator, returning the same as: base()[-n-1].
        {
            return base()[-n - 1];
        }

    private:
        iterator_type _type;
    };

    // relational operators for reverse iterator:
    
    template <class Iterator>
        bool operator==(const myReverse_iterator<Iterator>& lhs, 
                    const myReverse_iterator<Iterator>& rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator>
        bool operator!=(const myReverse_iterator<Iterator>& lhs,
                    const myReverse_iterator<Iterator>& rhs)
    {
        return !(lhs == rhs);
    }

   template <class Iterator>
        bool operator<(const myReverse_iterator<Iterator>& lhs,
                    const myReverse_iterator<Iterator>& rhs)
   {
       return lhs.base() > rhs.base();
   }

   template <class Iterator>
        bool operator<= (const myReverse_iterator<Iterator>& lhs,
                   const myReverse_iterator<Iterator>& rhs)
    {
        return lhs.base() >= rhs.base();
    }

    template <class Iterator>
        bool operator>  (const myReverse_iterator<Iterator>& lhs,
                   const myReverse_iterator<Iterator>& rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator>
        bool operator>= (const myReverse_iterator<Iterator>& lhs,
                   const myReverse_iterator<Iterator>& rhs)
    {
        return lhs.base() <= rhs.base();
    }
    
    template <class Iterator>
        myReverse_iterator<Iterator> operator+ (
             typename myReverse_iterator<Iterator>::difference_type n,
             const myReverse_iterator<Iterator>& rev_it)
    {
        return (reverse_iterator<Iterator>(rev_it.base() - n));
    }

    template <class Iterator>
        typename myReverse_iterator<Iterator>::difference_type operator- (
            const myReverse_iterator<Iterator>& lhs,
            const myReverse_iterator<Iterator>& rhs)
    {

    }

    

    // TO DO: Non-member function overloads for reverse iterator!!!
}

#endif