/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:29 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/22 17:39:32 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "Algorithm.hpp"
#include "Identifiers.hpp"
#include "MapIterator.hpp"
#include <utility>

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
        typedef less<key_type> key_compare;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename ft::MapIterator<pointer, TreeNode> iterator;
        typedef typename ft::MapIterator<const pointer, TreeNode> const_iterator;
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
            this->_last_node = allocate_tree_node();
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

        iterator begin()
        {
            return (iterator(min_node(this->_node)));
        }

        const_iterator begin() const;

        iterator end()
        {
            return (iterator(this->_last_node));
        }

        const_iterator end() const
        {
            return (const_iterator(this->_last_node));
        }

        reverse_iterator rbegin()
        {
            return (reverse_iterator(end()));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(end()));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(begin()));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(begin()));
        }

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

        /* The single element versions (1) return a pair,
        with its member pair::first set to an iterator pointing to either the newly inserted element
        or to the element with an equivalent key in the map. The pair::second element in the pair 
        is set to true if a new element was inserted or false if an equivalent key already existed. */

        std::pair<iterator, bool> insert(const value_type &val)
        {
            iterator iter;
            if (!this->_node) // Insert the first node, if root is NULL.
            {
                this->_node = allocate_tree_node();
                this->_allocator_type.construct(&_node->val, val);
                this->_last_node->parent = this->_node;
                this->_node->right = this->_last_node;
                iter = this->_node;
                return make_pair(iter, true);
            }
            else
            {
                TreeNode *new_node = construct_tree_node(val);
                TreeNode *root = _node;

                if (val.first <= _node->val.first)
                {
                    while (root->left)
                        root = root->left;
                    root->left = new_node;
                    new_node->right = NULL;
                    new_node->left = NULL;
                    new_node->parent = root;
                    iter = new_node;
                }
                else
                {
                    while (root->right != _last_node)
                        root = root->right;
                    root->right = new_node;
                    new_node->left = NULL;
                    new_node->right = _last_node;
                    _last_node->parent = new_node;
                    new_node->parent = root;
                    iter = _last_node;
                return make_pair(iter, true);
            }
        }

        // теперь нужно добавить вариант, когда возвращает false при добавлении того же ключа! 

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

        //  value_compare value_comp() const;

        /*================================ OPERATIONS: ================================*/

        iterator find(const key_type &k);

        const_iterator find(const key_type &k) const;

        size_type count(const key_type &k) const;

        iterator lower_bound(const key_type &k);

        const_iterator lower_bound(const key_type &k) const;

        iterator upper_bound(const key_type &k);

        const_iterator upper_bound(const key_type &k) const;

        std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const;

        std::pair<iterator, iterator> equal_range(const key_type &k);

        /*================================ HELPING FUNCTIONS : ================================*/

        TreeNode *allocate_tree_node()
        {
            TreeNode *node;

            node = this->_alloc_node.allocate(1);
            node->right = NULL;
            node->left = NULL;
            node->parent = NULL;
            std::memset(&node->val, 0, sizeof(node->val));
            return node;
        }

        TreeNode *construct_tree_node(const_reference val)
        {
            TreeNode *node;
            node = allocate_tree_node();
            this->_allocator_type.construct(&node->val, val);
            return (node);
        }

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

        TreeNode *min_node(TreeNode *node)
        {
            if (node)
            {
                while (node->left)
                    node = node->left;
            }
            return (node);
        }

    private:
        TreeNode *_node;
        TreeNode *_last_node;
        Compare _comp;
        allocator_type _allocator_type;
        node_allocator_type _alloc_node;
    };
}

#endif