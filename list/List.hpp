/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:06:11 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/12 21:59:49 by dbliss           ###   ########.fr       */
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
        typedef typename ft::myIterator<pointer, Node> iterator;
        typedef typename ft::myIterator<const_pointer, Node> const_iterator;
        typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

        typedef typename Alloc::template rebind<Node>::other node_allocator_type; // мб это не нужно, так как указала в приватных по=другому

        /*================================ 4 CONSTRUCTORS: ================================*/

        // #1 : DEFAULT:
        explicit list(const allocator_type &alloc = allocator_type())
        {
            this->_size = 0;
            this->_node = allocate_node();
        }

        // #2: FILL:
        explicit list(size_type n, const value_type &val = value_type(),
                      const allocator_type &alloc = allocator_type())
        {
            this->_node = allocate_node();
            for (int i = 0; i < n; ++i)
            {
                insert_end(val);
                this->_size++;
            }
        }

        // #3: RANGE:
        // template <class InputIterator>
        // list(InputIterator first, InputIterator last,
        //      const allocator_type &alloc = allocator_type()) {}

        // #4 COPY:
        list(const list &x) { *this = x; }

        /*================================ DESTRUCTOR: ================================*/

        virtual ~list() {}

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

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        /*================================ CAPACITY: ================================*/

        bool empty() const
        {
            return this->_node->next == this->_node;
        }

        size_type size() const
        {
            return this->_size;
        }

        size_type max_size() const
        {
            return this->_alloc_node.max_size();
        }

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

        /* Removes the last element in the list container, effectively reducing the container size by one. 
        This destroys the removed element. */
        void pop_back()
        {
            erase(end());
            // use allocator destroy
        }

        /* Removes from the list container a single element (position). 
        This effectively reduces the container size by the number of elements removed, which are destroyed.*/
        iterator erase(iterator position)
        {

            Node *next;

            next = position.get_node()->next;
            delete_node(position.get_node());
            return iterator(next);
        }

        /* Removes from the list container a range of elements ([first,last)).
        This effectively reduces the container size by the number of elements removed, which are destroyed.*/

        iterator erase(iterator first, iterator last)
        {
            Node *begin;
            Node *end;

            begin = first.get_node()->prev;
            end = last.get_node();
            begin->next = end;
            end->prev = begin;
            while (first != last)
            {
                this->_alloc_node.destroy(first.get_node());
                this->_alloc_node.deallocate(first.get_node(), 1);
                this->_size--;
                first++;
            }

            
            return (last);
            
            
        }

        /* Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0. */
        void clear();

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
            this->_size += 1;
        }

        void delete_node(Node *node)
        {
            this->_alloc_node.destroy(node);
            node->prev->next = node->next;
            node->next->prev = node->prev;
            this->_alloc_node.deallocate(node, 1);
            this->_size -= 1;
        }

    private:
        allocator_type _allocator_type;
        node_allocator_type _alloc_node;
        size_type _size;
        Node *_node;
    };

    /*================================ NON-MEMBER FUNCITON OVERLOADS: ================================*/

}
#endif