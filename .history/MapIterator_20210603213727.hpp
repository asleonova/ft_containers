/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:31:27 by dbliss            #+#    #+#             */
/*   Updated: 2021/06/03 21:37:27 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

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

    template <class T, class TreeNode, class Compare>
    class MapIterator
    {
    public:
        typedef Compare key_compare;

    private:
        TreeNode *_node;
        key_compare _comp;

    public:
        typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<T>::value_type value_type;
        typedef typename ft::iterator_traits<T>::difference_type difference_type;
        typedef typename ft::iterator_traits<T>::reference reference;
        typedef typename ft::iterator_traits<T>::pointer pointer;

        /*================================ CONSTRUCTORS: ================================*/

        MapIterator(TreeNode *node = 0) : _node(node) {} // default

        template <class Iter>
        MapIterator(MapIterator<Iter, TreeNode, key_compare> const &my_it) : _node(my_it.get_node()) {} // Copy constructor

        MapIterator &operator=(MapIterator<T, TreeNode, key_compare> const &rhs) // asignment operator
        {
            this->_node = rhs.get_node();
            this->_comp = rhs._comp;
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
                while (tmp->parent && _comp(tmp->val.first, _node->val.first)) // tmp->val.first < _node->val.first
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
                while (tmp->parent && _comp(_node->val.first, tmp->val.first)) // _node->val.first < tmp->val.first
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

    template <class Iterator, class TreeNode, class Compare>
    class MapIterator : public myReverseIterator
    {


        virtual MapIterator &operator++()
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
                while (tmp->parent && _comp(_node->val.first, tmp->val.first)) // _node->val.first < tmp->val.first
                    tmp = tmp->parent;
            }
            _node = tmp;
            return (*this);
        }

        virtual MapIterator operator++(int)
        {
            myReverseIterator base_copy(*this);
            operator--();
            return (base_copy);
        }

        virtual MapIterator &operator--()
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
                while (tmp->parent && _comp(tmp->val.first, _node->val.first)) // tmp->val.first < _node->val.first
                    tmp = tmp->parent;
            }
            _node = tmp;
            return (*this);
        }

        virtual MapIterator operator--(int)
        {
            MapIterator base_copy(*this);
            operator++();
            return (base_copy);
        }
    };
}

#endif
