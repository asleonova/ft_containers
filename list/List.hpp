/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:06:11 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/09 20:43:20 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include "Iterator.hpp"

namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class list
    {
    private:

        struct Node
        {
            T val;
            Node *next;
            Node *prev;
        };
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename ft::myIterator<value_type, Node> iterator;
        typedef typename ft::myIterator<const value_type, Node> const_iterator;
        // typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        // typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

        typedef typename Alloc::template rebind<Node>::other node_allocator_type; // мб это не нужно, так как указала в приватных по=другому

        /*================================ 4 CONSTRUCTORS: ================================*/

        // #1 : DEFAULT:
        explicit list(const allocator_type &alloc = allocator_type())
        {
            this->_node = allocate_node();
        }

        // #2: FILL:
        explicit list(size_type n, const value_type &val = value_type(),
                      const allocator_type &alloc = allocator_type())
        {
            this->_node = allocate_node();
            for (int i = 0; i < n; ++i)
                insert_end(val);
        }

        // #3: RANGE:
        // template <class InputIterator>
        // list(InputIterator first, InputIterator last,
        //      const allocator_type &alloc = allocator_type()) {}

        // #4 COPY:
        list(const list &x) { *this = x; }

        /*================================ DESTRUCTOR: ================================*/

        ~list() {}

        /*================================ OPERATOR=: ================================*/
        list &operator=(const list &x)
        {
            if (this != &x)
            {
                assign(x.begin(), x.end());
            }
            return (*this);
        }

        /*================================ ITERATORS: ================================*/

        iterator begin()
        {
            return iterator(this->_node->next);
        }

        const_iterator begin() const
        {
            return const_iterator(this->_node->next);
        }

        iterator end()
        {
            return iterator(this->_node);
        }

        const_iterator end() const
        {
            return const_iterator(this->_node);
        }

        /*================================ CAPACITY: ================================*/

        /*================================ ELEMENT ACCESS: ================================*/
        reference front()
        {
            return this->_node->next->val;
        }

        const_reference front() const
        {
            return this->_node->next->val;
        }

        reference back()
        {
            return this->_node->prev->val;
        }

        const_reference back() const
        {
            return this->_node->prev->val;
        }

        /*================================ MODIFIERS: ================================*/

        void push_back(const value_type &val)
        {
           insert_end(val);
        }

        /*================================ OPERATIONS: ================================*/

        /*================================ PRIVATE FUNCS: ================================*/

        Node *allocate_node()
        {
            Node *node;

            node = this->_alloc_node.allocate(1);
            node->next = node;
            node->prev = node;
            std::memset(&node->val, 0, sizeof(node->val));
            return node;
        }

        Node *construct_node(const_reference val)
        {
            Node *node;
            node = allocate_node();
            this->_allocator_type.construct(&node->val, val);
            return (node);
        }

        void insert_end(const_reference val)
        {
            // find last node
            Node *last = this->_node->prev;

            // create new node
            Node *new_node;
           // Node *new_node = allocate_node();
            new_node = construct_node(val);

            // start is going to be next of new_node
            new_node->next = this->_node;

            // make new_node previous of start
            this->_node->prev = new_node;

            // make last previous of new node
            new_node->prev = last;

            // make new node next of old start
            last->next = new_node;
        }

    private:
        allocator_type _allocator_type;
        node_allocator_type _alloc_node;
        Node *_node;
    };

    /*================================ NON-MEMBER FUNCITON OVERLOADS: ================================*/

}
#endif