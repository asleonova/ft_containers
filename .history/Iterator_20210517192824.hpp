/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:03 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/17 19:28:24 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "Vector.hpp"

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
        // input_iterator_tag; output_iterator_tag; forward_iterator_tag; bidireational_iterator_tag; myIterator_tag; myIterator_tag;
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
        typedef const T *pointer;
        typedef const T &reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template <class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance(InputIterator first, InputIterator last)
    {
        typename iterator_traits<InputIterator>::difference_type ret(0);
        for (; first != last; ++first)
            ++ret;
        return ret;
    }

    template <class T>
    class myIterator : public ft::iterator<ft::random_access_iterator_tag, T>
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

        // PROBABLY DON'T NEED THIS
        explicit myIterator(const T &it) : _ptr(it) {} // initialization constructor

        template <class Iter>
        myIterator(const myIterator<Iter> &my_it) : _ptr(my_it.base()) {} // copy constructor

        myIterator &operator=(myIterator const &rhs) // asignment operator
        {
            this->_ptr = rhs.base();
            return (*this);
        }

        ~myIterator() {} // destructor

        const T &base() const // returns a copy of the base iterator
        {
            return (_ptr);
        }

        myIterator &operator++()
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

        myIterator &operator--() //--a
        {
            this->_ptr--;
            return (*this);
        }
        myIterator operator--(int) // a--
        {
            myIterator copy(*this);
            this->_ptr--;
            return (copy);
        }

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

        // Arithmetic operations + -

        myIterator operator+(difference_type n) const // between an myIterator and int value
        {
            return (myIterator(this->_ptr + n));
        }

        myIterator operator-(difference_type n) const // between an myIterator and int value
        {
            return (myIterator(this->_ptr - n));
        }

        reference operator*() const
        {
            return *this->_ptr;
        }

        pointer operator->() const
        {
            return this->_ptr;
        }

        reference operator[](difference_type n) const
        {
            return (*(this->_ptr + n));
        }
    };

    // Relational operators:

    template <typename T, typename Y>
    bool operator==(const myIterator<T> &lhs,
                    const myIterator<Y> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <typename T, typename Y>
    bool operator!=(const myIterator<T> &lhs,
                    const myIterator<Y> &rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <typename T, typename Y>
    bool operator<(const myIterator<T> &lhs,
                   const myIterator<Y> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename T, typename Y>
    bool operator<=(const myIterator<T> &lhs,
                    const myIterator<Y> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename T, typename Y>
    bool operator>(const myIterator<T> &lhs,
                   const myIterator<Y> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <typename T, typename Y>
    bool operator>=(const myIterator<T> &lhs,
                    const myIterator<Y> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <typename T>
    myIterator<T> operator+(
        typename myIterator<T>::difference_type n,
        const myIterator<T> &m_it)
    // Returns a move iterator pointing to the element located n positions away from the element pointed to by m_it.
    {
        return (myIterator<T>(m_it.base() + n));
    }

    // Returns the distance between lhs and rhs

    template <typename T, typename Y>
    typename myIterator<T>::difference_type
    operator-(const myIterator<T> &lhs,
              const myIterator<Y> &rhs)
    {
        return lhs.base() - rhs.base();
    }

    /* REVERSE ITERATOR FUNCTIONS*/

    template <class Iterator>
    class myReverse_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
                                                   typename ft::iterator_traits<Iterator>::value_type, typename ft::iterator_traits<Iterator>::difference_type,
                                                   typename ft::iterator_traits<Iterator>::pointer, typename ft::iterator_traits<Iterator>::reference>
    {
    public:
        typedef Iterator iterator_type;

        // try to comment this things
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;

        myReverse_iterator() {} // default

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
            this->_type++;
            return (base_copy);
        }

        myReverse_iterator &operator-=(difference_type n)
        {
            this->_type += n;
            return (*this);
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        reference operator[](difference_type n) const // Internally, the function accesses the proper element of its base iterator, returning the same as: base()[-n-1].
        {
            return base()[-n - 1];
        }

    private:
        iterator_type _type;
    };

    // relational operators for reverse iterator:

    template <class Iterator>
    bool operator==(const myReverse_iterator<Iterator> &lhs,
                    const myReverse_iterator<Iterator> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator>
    bool operator!=(const myReverse_iterator<Iterator> &lhs,
                    const myReverse_iterator<Iterator> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class Iterator>
    bool operator<(const myReverse_iterator<Iterator> &lhs,
                   const myReverse_iterator<Iterator> &rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator>
    bool operator<=(const myReverse_iterator<Iterator> &lhs,
                    const myReverse_iterator<Iterator> &rhs)
    {
        return lhs.base() >= rhs.base();
    }

    template <class Iterator>
    bool operator>(const myReverse_iterator<Iterator> &lhs,
                   const myReverse_iterator<Iterator> &rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator>
    bool operator>=(const myReverse_iterator<Iterator> &lhs,
                    const myReverse_iterator<Iterator> &rhs)
    {
        return lhs.base() <= rhs.base();
    }

    template <class Iterator>
    myReverse_iterator<Iterator> operator+(
        typename myReverse_iterator<Iterator>::difference_type n,
        const myReverse_iterator<Iterator> &rev_it)
    // returns an iterator pointing to the element n positions away from rev_it.
    {
        return (myReverse_iterator<Iterator>(rev_it.base() - n));
    }

    template <class Iterator>
    typename myReverse_iterator<Iterator>::difference_type operator-(
        const myReverse_iterator<Iterator> &lhs,
        const myReverse_iterator<Iterator> &rhs)
    // The function returns the same as subtracting lhs's base iterator from rhs's base iterator.
    {
        return rhs.base() - lhs.base();
    }
}

#endif