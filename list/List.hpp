/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:06:11 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/13 16:14:14 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include "Iterator.hpp"
#include "Identifiers.hpp"

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

        virtual ~list()
        {
            erase(begin(), end());
            // The next steps we nee to do for allocated node in the constructor.
            this->_node->prev->next = this->_node->next;
            this->_node->next->prev = this->_node->prev;
            this->_alloc_node.deallocate(this->_node, 1);
        }

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

        /* ASSIGN */
        /* Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly. */

        /* In the range version (1), the new contents are elements constructed 
        from each of the elements in the range between first and last, in the same order.*/
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIterator = InputIterator())
        {
            (void)isIterator;
            clear();
            insert(begin(), first, last);
        }


        /* In the fill version (2), the new contents are n elements,
            each initialized to a copy of val.*/
        void assign (size_type n, const value_type& val)
        {
            clear();
            insert(begin(), n, val);
        }

        /* Insert element at the beginning */
        void push_front (const value_type& val)
        {
            insert_begin(val);
        }

        /* Removes the first element in the list container, effectively reducing its size by one. */
        void pop_front()
        {
            erase(begin());
        }


        void push_back(const value_type &val)
        {
            insert_end(val);
        }

        /* Removes the last element in the list container, effectively reducing the container size by one. 
        This destroys the removed element. */
        void pop_back()
        {
            erase(--end()); 
            // --end because the result of end an iterator to the element past the end of the sequence.
        }

        /* INSERT */
        /* The container is extended by inserting new elements before 
            the element at the specified position. */

        iterator insert (iterator position, const value_type& val)
        {
            Node* new_node = construct_node(val);

            // Inderting new node before the position
			new_node->next = position.get_node();
			new_node->prev = position.get_node()->prev;
			position.get_node()->prev->next = new_node;
			position.get_node()->prev = new_node;

            this->_size++;
			return iterator(new_node);
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            for (int i = 0; i < n; ++i)
            {
                insert(position, val);
            }

        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,  typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIterator = InputIterator())
        {
            (void)isIterator;
            while (first != last)
            {
				position = insert(position, *first);
				++position;
				++first;
			}
            
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

        void swap (list& x);

        void resize (size_type n, value_type val = value_type());

        

        /* Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0. */
        void clear()
        {
            erase(begin(), end());
        }

        /*================================ OPERATIONS: ================================*/

        /* SPLICE */

        void splice (iterator position, list& x);
        void splice (iterator position, list& x, iterator i);
        void splice (iterator position, list& x, iterator first, iterator last);

        /* REMOVE */

        void remove (const value_type& val);
        
        /* REMOVE IF */

        template <class Predicate>
        void remove_if (Predicate pred);

        /* UNIQUE */
        void unique();

        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred);

        /* MERGE */
        void merge (list& x);

        template <class Compare>
        void merge (list& x, Compare comp);

        /* SORT */
        void sort();
        
        template <class Compare>
        void sort (Compare comp);

        /* REVERSE */
        void reverse();

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

        void insert_between(const_reference val1, const_reference val2)
        {
            Node *new_node = construct_node(val1);
            
            Node *tmp = this->_node;
            while (tmp->val != val2)
                tmp = tmp->next;
            Node *next = tmp->next;

            //insert new node between tmp and next
            tmp->next = new_node;
            new_node->prev = tmp;
            new_node->next = next;
            next->prev = new_node;

        }

        void insert_begin(const_reference val)
        {
            // Pointer points to the last Node
            Node *last = this->_node->prev;

            Node *new_node;
            new_node = construct_node(val); // Inserting the data

            // Setting up previous and next of new node
            new_node->next = this->_node;
            new_node->prev = last;

            // Update next and previous pointers of start and last
            last->next = this->_node->prev = new_node;

            // Update start pointer
            this->_node = new_node;
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