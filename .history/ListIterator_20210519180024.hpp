/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:31:27 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/19 18:00:24 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

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
        typedef bidirectional_iterator_tag iterator_category;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef bidirectional_iterator_tag iterator_category;
    };

    template <class T, class Node>
    class ListIterator
    {
    private:
        Node *_node;

    public:
        typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<T>::value_type value_type;
        typedef typename ft::iterator_traits<T>::difference_type difference_type;
        typedef typename ft::iterator_traits<T>::reference reference;
        typedef typename ft::iterator_traits<T>::pointer pointer;

        /*================================ CONSTRUCTORS: ================================*/

        ListIterator(Node *node = 0) : _node(node) {} // default

        template <class Iter>
        ListIterator(ListIterator<Iter, Node> const &my_it) : _node(my_it.get_node()) {} // Copy constructor

        ListIterator &operator=(ListIterator<T, Node> const &rhs) // asignment operator
        {
            this->_node = rhs.get_node();
            return (*this);
        }

        /*================================ DESTRUCTOR: ================================*/

        virtual ~ListIterator(){};

        /*================================ HELPING FUNCTIONS: ================================*/

        Node *get_node() const
        {
            return this->_node;
        }

        /*================================ INCREMENTS: ================================*/

        ListIterator &operator++() // ++a
        {
            this->_node = this->_node->next;
            return (*this);
        }

        ListIterator operator++(int) //a++
        {
            ListIterator copy(*this);
            this->_node = this->_node->next;
            return (copy);
        }

        /*================================ DECREMENT: ================================*/

        ListIterator &operator--() //--a
        {
            this->_node = this->_node->prev;
            return (*this);
        }
        ListIterator operator--(int) // a--
        {
            ListIterator copy(*this);
            this->_node = this->_node->prev;
            return (copy);
        }

        /*================================ DEREFERENCE: ================================*/

        reference operator*()
        {
            return (this->_node->val);
        }

        pointer operator->(void)
        {

            return &(this->_node->val);
        }

        /*================================ EQUALITY / INEQUALITY COMPARISONS: ================================*/

        bool operator==(const ListIterator &rhs)
        {
            return this->_node == rhs._node;
        }

        bool operator!=(const ListIterator &rhs)
        {
            return this->_node != rhs._node;
        }
    };
}

#endif
