/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:29 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/19 20:57:15 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "Algorithm.hpp"
#include "Identifiers.hpp"

namespace ft
{
    template <class Key, class T,
              class Compare = less<Key>,
              class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {

    private:
        struct TreeNode
        {
            T val;
            TreeNode *left;
            TreeNode *right;
            TreeNode *parent;
        };

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        //typedef typename ft::ListIterator<pointer, Node> iterator;
        //typedef typename ft::ListIterator<const_pointer, Node> const_iterator;
        //typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        //typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef typename Alloc::template rebind<TreeNode>::other node_allocator_type;

        /*================================ 4 CONSTRUCTORS: ================================*/

        /* EMPTY */
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type());

        /*RANGE*/

        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type());

        /*COPY*/
        map(const map &x);

        /*================================ DESTRUCTOR: ================================*/

        virtual ~map() {}

        /*================================ OPERATOR=: ================================*/

        map &operator=(const map &x);

        /*================================ ITERATORS: ================================*/

        iterator begin();

        const_iterator begin() const;

        iterator end();

        const_iterator end() const;

        reverse_iterator rbegin();

        const_reverse_iterator rbegin() const;

        reverse_iterator rend();

        const_reverse_iterator rend() const;

        /*================================ CAPACITY: ================================*/

        bool empty() const;

        size_type size() const;

        size_type max_size() const;

        /*================================ ELEMENT ACCESS: ================================*/

        mapped_type &operator[](const key_type &k)
        {
            //return (*((this->insert(make_pair(k,mapped_type()))).first)).second);
        }

        /*================================ MODIFIERS: ================================*/

        /* INSERT */

        pair<iterator, bool> insert(const value_type &val);

        iterator insert(iterator position, const value_type &val);

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);

        /* ERASE */

        void erase(iterator position);

        size_type erase(const key_type &k);

        void erase(iterator first, iterator last);

        /* SWAP */

        void swap(map &x);

        /* CLEAR */

        void clear();

        /*================================ OBSERVERS: ================================*/

        key_compare key_comp() const;

        value_compare value_comp() const;

        /*================================ OPERATIONS: ================================*/

        iterator find(const key_type &k);

        const_iterator find(const key_type &k) const;

        size_type count(const key_type &k) const;

        iterator lower_bound(const key_type &k);

        const_iterator lower_bound(const key_type &k) const;

        iterator upper_bound(const key_type &k);

        const_iterator upper_bound(const key_type &k) const;

        pair<const_iterator, const_iterator> equal_range(const key_type &k) const;

        pair<iterator, iterator> equal_range(const key_type &k);

    private:
        TreeNode *_node;
        TreeNode *_last;
        Compare _comp;
        allocator_type _allocator_type;
        node_allocator_type _alloc_node;

    };

}

#endif