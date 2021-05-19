/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:31:47 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/19 17:43:48 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "Iterators.hpp"

namespace ft
{
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

       virtual ~myIterator() {} // destructor

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
}

#endif