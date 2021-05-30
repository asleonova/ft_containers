/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:31:27 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/30 16:47:13 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "Iterators.hpp"

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

    template <class T, class TreeNode>
    class MapIterator
    {
    private:
        TreeNode *_node;

    public:
        typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<T>::value_type value_type;
        typedef typename ft::iterator_traits<T>::difference_type difference_type;
        typedef typename ft::iterator_traits<T>::reference reference;
        typedef typename ft::iterator_traits<T>::pointer pointer;

        /*================================ CONSTRUCTORS: ================================*/

        MapIterator(TreeNode *node = 0) : _node(node) {} // default

        template <class Iter>
        MapIterator(MapIterator<Iter, TreeNode> const &my_it) : _node(my_it.get_node()) {} // Copy constructor

        MapIterator &operator=(MapIterator<T, TreeNode> const &rhs) // asignment operator
        {
            this->_node = rhs.get_node();
            return (*this);
        }

        /*================================ DESTRUCTOR: ================================*/

        virtual ~MapIterator(){};

        /*================================ HELPING FUNCTIONS: ================================*/

        TreeNode *get_node() const
        {
            return this->_node;
        }

        /*================================ INCREMENTS: ================================*/

        MapIterator &operator++()
        {
            TreeNode *tmp = _node;
            // _last_node->right == _first  and  _first->left == NULL
            // _last->right == _last_node   and  _last_node->left  == _last
            if (_node->right)
            {
                tmp = _node->right;
                while (tmp->left && tmp->left != _node)
                    tmp = tmp->left;
            }
            else if (_node->parent)
            {
                tmp = _node->parent;
                while (tmp->parent && tmp->val.first < _node->val.first)
                    tmp = tmp->parent;
            }
            _node = tmp;
            return (*this);
        }

        MapIterator operator++(int) //a++
        {
            MapIterator copy(*this);
            operator++();
            return (copy);
        }

        /*================================ DECREMENT: ================================*/

        MapIterator &operator--()
        {
            TreeNode *tmp = _node;
            // _last_node->left == _last  and  _last->right == _last_node
            // _last->left == tmp    and  tmp->right   == NULL
            if (_node->left)
            {
                tmp = _node->left;
                while (tmp->right && tmp->right != _node)
                    tmp = tmp->right;
            }
            else if (_node->parent)
            {
                tmp = _node->parent;
                while (tmp->parent &&  _node->val.first < tmp->val.first)
                    tmp = tmp->parent;
            }
            _node = tmp;
            return (*this);
        }

        MapIterator operator--(int) // a--
        {
            MapIterator copy(*this);
            operator--();
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

        bool operator==(const MapIterator &rhs)
        {
            return this->_node == rhs._node;
        }

        bool operator!=(const MapIterator &rhs)
        {
            return this->_node != rhs._node;
        }
    };
}

#endif
