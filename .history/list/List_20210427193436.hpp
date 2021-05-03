/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:06:11 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/27 19:34:36 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class list
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename ft::myIterator<value_type> iterator;
        typedef typename ft::myIterator<const value_type> const_iterator;
        typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef typename allocator_type::template

        /*================================ 4 CONSTRUCTORS: ================================*/

        // #1 : DEFAULT:
        explicit list(const allocator_type &alloc = allocator_type())
        {
            Node* allocate_node() {
			Node* node;

			node       = node_alloc_.allocate(1);
			node->next = node;
			node->prev = node;
			return node;
		}
        }

        // #2: FILL:
        explicit list(size_type n, const value_type &val = value_type(),
                      const allocator_type &alloc = allocator_type()) {}

        // #3: RANGE:
        template <class InputIterator>
        list(InputIterator first, InputIterator last,
             const allocator_type &alloc = allocator_type()) {}

        // #4 COPY:
        list(const list &x) { *this = src }

        /*================================ DESTRUCTOR: ================================*/

        ~list() {}

        /*================================ OPERATOR=: ================================*/
        list &operator=(const list &x)
        {
            if (this != &rhs)
            {
                assign(x.begin(), x.end());
            }
            return (*this);
        }

        /*================================ ITERATORS: ================================*/


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

       /*================================ OPERATIONS: ================================*/

        

    private:

        struct Node
        {
            T val;
            Node *next;
            Node *prev;
        };
        
		allocator_type       _allocator_type;
		std::allocator<Node> _alloc_node;
        Node *_node;
    };

    /*================================ NON-MEMBER FUNCITON OVERLOADS: ================================*/
    
}
#endif