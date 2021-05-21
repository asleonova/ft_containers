/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:29 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/21 14:20:43 by dbliss           ###   ########.fr       */
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

       // template <class T>
        struct TreeNode
        {
            std::pair<const Key, T> val;
            TreeNode *left;
            TreeNode *right;
            TreeNode *parent;
            unsigned char height;
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
        typedef typename ft::MapIteraror<T, TreeNode> iterator;
        typedef typename ft::MapIterator<T, TreeNode> const_iterator;
        typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef typename Alloc::template rebind<TreeNode>::other node_allocator_type;

        /*================================ 4 CONSTRUCTORS: ================================*/

        /* EMPTY */
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : _node(NULL), _comp(comp), _allocator_type(alloc)
        {
            this->_node = allocate_tree_node();
        }

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

        /*================================ HELPING FUNCTIONS : ================================*/

        unsigned char height(TreeNode *p)
        {
            if (p)
                return p->height;
            else
                return 0;
        }

        int balanceFactor(TreeNode *p)
        {
            return height(p->right) - height(p->left);
        }

        void fixHeight(TreeNode *p)
        {
            unsigned char hl = height(p->left);
            unsigned char hr = height(p->right);
            p->height = (hl > hr ? hl : hr) + 1; // +1 for root
        }

        TreeNode *rotateright(TreeNode *p) // правый поворот вокруг p
        {
            TreeNode *q = p->left;
            p->left = q->right;
            q->right = p;
            fixheight(p);
            fixheight(q);
            return q;
        }

        TreeNode *rotateleft(TreeNode *q) // левый поворот вокруг q
        {
            TreeNode *p = q->right;
            q->right = p->left;
            p->left = q;
            fixheight(q);
            fixheight(p);
            return p;
        }

    private:
        TreeNode <value_type> _node;
        TreeNode <value_type> _last_node;
        Compare _comp;
        allocator_type _allocator_type;
        node_allocator_type _alloc_node;
    };

}

#endif