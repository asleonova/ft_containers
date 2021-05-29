/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:31:27 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/29 18:07:46 by dbliss           ###   ########.fr       */
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

    template <class T, class TreeNode>
    class MapIterator
    {
    private:
        TreeNode *_node;
        TreeNode *_last_node;

    public:
        typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<T>::value_type value_type;
        typedef typename ft::iterator_traits<T>::difference_type difference_type;
        typedef typename ft::iterator_traits<T>::reference reference;
        typedef typename ft::iterator_traits<T>::pointer pointer;

        /*================================ CONSTRUCTORS: ================================*/

        MapIterator(TreeNode *node = 0, TreeNode *last_node = 0) : _node(node), _last_node(last_node) {} // default

        template <class Iter>
        MapIterator(MapIterator<Iter, TreeNode> const &my_it) : _node(my_it.get_node()), _last_node(my_it.get_last_node()) {} // Copy constructor

        MapIterator &operator=(MapIterator<T, TreeNode> const &rhs) // asignment operator
        {
            this->_node = rhs.get_node();
            this->_last_node = rhs.get_last_node();
            return (*this);
        }

        /*================================ DESTRUCTOR: ================================*/

        virtual ~MapIterator(){};

        /*================================ HELPING FUNCTIONS: ================================*/

        TreeNode *get_node() const
        {
            return this->_node;
        }

        TreeNode *get_last_node() const
        {
            return this->_last_node;
        }

        /*================================ INCREMENTS: ================================*/

        MapIterator &operator++() //pre increment
        {
            TreeNode *y;
            if (_node->right && _node->right != _last_node)
            {
                y = _node->right;
                while (y->left)
                    y = y->left;
                _node = y;
            }
            else if (_node->parent)
            {
                y = _node->parent;
                while (_node == y->right && _node->right != _last_node)
                {
                    _node = y;
                    y = y->parent;
                }
                this->_node = y;
            }
            _node = y; 
            return (*this);
        }
        //     MapIterator &operator++() // ++a
        //     {
        //         TreeNode *tmp = _node;
        //         if (_node->right)
        //         {
        //             tmp = _node->right;
        //             while (tmp->left && tmp != _last_node)
        //                 tmp = tmp->left;
        //             _node = tmp;

        //         }
        //         // else if (_node->parent)
        //         // {
        //         //     tmp = _node->parent;
        //         //     while (tmp->parent && tmp->val.first < _node->val.first)
        //         //     {
        //         //       //  _node = tmp;
        //         //         tmp = tmp->parent;
        //         //     }
        //         // }
        //         else
        //         {
        //              while (_node->parent && _node->parent->parent && _node == _node->parent->right)
        //                     _node = _node->parent;
        //              _node = _node->parent;

        //         }
        //         // _node = tmp;
        //     return (*this);
        // }

        MapIterator operator++(int) //a++
        {
            MapIterator copy(*this);
            operator++();
            return (copy);
        }

        /*================================ DECREMENT: ================================*/

        MapIterator &operator--() //--a
        {
            if (_node->left)
            {
                this->_node = this->_node->left;
                while (this->_node->right)
                    this->_node = this->_node->right;
            }
            else
            {
                TreeNode *y = this->_node->parent;

                while (_node == y->left)
                {
                    _node = y;
                    y = y->parent;
                }
                _node = y;
            }
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
