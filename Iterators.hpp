/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:03 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/30 16:53:17 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

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
        // input_iterator_tag; output_iterator_tag; forward_iterator_tag; bidireational_iterator_tag; ListIterator_tag; ListIterator_tag;
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


    template <class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance(InputIterator first, InputIterator last)
    {
        typename iterator_traits<InputIterator>::difference_type ret(0);
        for (; first != last; ++first)
            ++ret;
        return ret;
    }

    /* REVERSE ITERATOR FUNCTIONS*/

    template <class Iterator>
        class myReverseIterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
                                                      typename ft::iterator_traits<Iterator>::value_type, typename ft::iterator_traits<Iterator>::difference_type,
                                                      typename ft::iterator_traits<Iterator>::pointer, typename ft::iterator_traits<Iterator>::reference>
        {
        public:
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;

            myReverseIterator() {} // default

            explicit myReverseIterator(iterator_type type) : _type(type) {} // initialization constructor

            template <class Iter>
            myReverseIterator(const myReverseIterator<Iter> &rev_type) : _type(rev_type.base()) {}

            iterator_type base() const // returns a copy of the base iterator
            {
                return (_type);
            }

            reference operator*() const // Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it.
            {
                iterator_type base_copy = this->_type;
                return *(--base_copy);
            }

            myReverseIterator operator+(difference_type n) const // Internally, the function applies the binary operator- on the base iterator and returns a reverse iterator constructed with the resulting iterator value.
            {
                return myReverseIterator(this->_type - n);
            }

            myReverseIterator &operator++() // Internally, the pre-increment version (1) decrements the base iterator kept by the object (as if applying operator-- to it).
            {
                this->_type--;
                return (*this);
            }

            myReverseIterator operator++(int)
            {
                myReverseIterator base_copy(*this);
                this->_type--;
                return (base_copy);
            }

            myReverseIterator &operator+=(difference_type n) // Internally, the function decreases by n the base iterator kept by the object (as if applying operator-= to it)
            {
                this->_type -= n;
                return (*this);
            }

            myReverseIterator operator-(difference_type n) const
            {
                return myReverseIterator(this->_type + n);
            }

            myReverseIterator &operator--()
            {
                this->_type++;
                return (*this);
            }

            myReverseIterator operator--(int)
            {
                myReverseIterator base_copy(*this);
                this->_type++;
                return (base_copy);
            }

            myReverseIterator &operator-=(difference_type n)
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
        bool operator==(const myReverseIterator<Iterator> &lhs,
                        const myReverseIterator<Iterator> &rhs)
        {
            return lhs.base() == rhs.base();
        }

        template <class Iterator>
        bool operator!=(const myReverseIterator<Iterator> &lhs,
                        const myReverseIterator<Iterator> &rhs)
        {
            return !(lhs == rhs);
        }

        template <class Iterator>
        bool operator<(const myReverseIterator<Iterator> &lhs,
                       const myReverseIterator<Iterator> &rhs)
        {
            return lhs.base() > rhs.base();
        }

        template <class Iterator>
        bool operator<=(const myReverseIterator<Iterator> &lhs,
                        const myReverseIterator<Iterator> &rhs)
        {
            return lhs.base() >= rhs.base();
        }

        template <class Iterator>
        bool operator>(const myReverseIterator<Iterator> &lhs,
                       const myReverseIterator<Iterator> &rhs)
        {
            return lhs.base() < rhs.base();
        }

        template <class Iterator>
        bool operator>=(const myReverseIterator<Iterator> &lhs,
                        const myReverseIterator<Iterator> &rhs)
        {
            return lhs.base() <= rhs.base();
        }

        template <class Iterator>
        myReverseIterator<Iterator> operator+(
            typename myReverseIterator<Iterator>::difference_type n,
            const myReverseIterator<Iterator> &rev_it)
        // returns an iterator pointing to the element n positions away from rev_it.
        {
            return (myReverseIterator<Iterator>(rev_it.base() - n));
        }

        template <class Iterator>
        typename myReverseIterator<Iterator>::difference_type operator-(
            const myReverseIterator<Iterator> &lhs,
            const myReverseIterator<Iterator> &rhs)
        // The function returns the same as subtracting lhs's base iterator from rhs's base iterator.
        {
            return rhs.base() - lhs.base();
        }
}

#endif