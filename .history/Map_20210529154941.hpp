/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:29 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/29 15:49:41 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "Algorithm.hpp"
#include "Identifiers.hpp"
#include "MapIterator.hpp"
#include <utility>
#include <iomanip>
#include <math.h>

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
            int height;
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
            // if (!_last_node->left) // in the last node I always update the min value after insertion
            //     return(iterator(_node));
            // return (iterator(_last_node->left));
            return(iterator(min_node(_node));
        }

        const_iterator begin() const;

        iterator end()
        {
            return (iterator(_last_node));
        }

        const_iterator end() const
        {
            return (const_iterator(_last_node));
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

        size_type size() const
        {
            if (!_node)
                return (0);
            return (tree_size(_node));
        }

        size_type max_size() const
        {
            return this->_alloc_node.max_size();
        }

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

        TreeNode *new_node(const value_type &val)
        {
            TreeNode *node;
            node = _alloc_node.allocate(1);
            _allocator_type.construct(&node->val, val);
            node->right = NULL;
            node->left = NULL;
            node->parent = NULL;
            node->height = 1; // new node is initially
                              // added at leaf

            return (node);
        }

        // std::pair<iterator, bool>
        // insert(const value_type &val)
        // {
        //     TreeNode *current = _node; // x
        //     TreeNode *parent = NULL; // y
        //     TreeNode *tmp = NULL; // node

        //         // unlink end
        //         while (current) //x
        //     {
        //         parent = current;
        //         if (current->val.first == val.first)
        //             return make_pair(iterator(current), false);
        //         if (val.first < current->val.first)
        //         {
        //             current = current->left;
        //         }
        //         else
        //         {
        //             current = current->right;
        //         }
        //     }
        //     tmp = new_node(val);
        //     tmp->parent = parent;
        //     if (parent == nullptr)
        //     {
        //         _node = tmp;
        //     }
        //     else if (tmp->val.first < parent->val.first)
        //     {
        //         parent->left = tmp;
        //     }
        //     else
        //     {
        //         parent->right = tmp;
        //     }

        //     // if (tmp->parent->parent == NULL)
        //     //     return make_pair(iterator(tmp), true);
        //     insertFix(tmp, val);
        //     return make_pair(iterator(tmp), true);
        //      // link end (find min, find max, put left to min. right to last node)
        // }

        TreeNode *insertFix(TreeNode *node, const value_type &val)
        {
            if (node->parent)
                node->parent->height = 1 + max(height(node->left),
                                               height(node->right));

            /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
            int balance = getBalance(node);

            // If this node becomes unbalanced, then
            // there are 4 cases

            // Left Left Case
            if (balance > 1 && val.first < node->left->val.first)
                return rightRotate(node);

            // Right Right Case
            if (balance < -1 && val.first > node->right->val.first)
                return leftRotate(node);

            // Left Right Case
            if (balance > 1 && val.first > node->left->val.first)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Right Left Case
            if (balance < -1 && val.first < node->right->val.first)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            /* return the (unchanged) node pointer */
            return node;
        }

        void unlink_end()
        {
            _last_node->right->right = NULL;
        }

        void link_end()
        {
            TreeNode *max = max_node(_node);
            max->right = _last_node;
            _last_node->right = max;
            _last_node->left = min_node(_node);
          
        }

        std::pair<iterator, bool>
        insert(const value_type &val)
        {
            if (_last_node->right)
                unlink_end();

            TreeNode *current = _node;
            TreeNode *tmp;
            
            while (current)
            {
                if (current->val.first == val.first)
                    return make_pair(iterator(current), false);
                if (val.first < current->val.first)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            _node = insert_node(_node, val);
            current = _node;
            while (current)
            {
                tmp = current;
                if (val.first < current->val.first)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            // if (tmp->right != _last_node)
            //     tmp = tmp->right;
           link_end();
           return std::make_pair(iterator(tmp), true);
        }

        // std::pair<iterator, bool> insert(const value_type &val)
        // {
        //     iterator iter;
        //     if (!this->_node) // Insert the first node, if root is NULL.
        //     {
        //         this->_node = allocate_tree_node();
        //         this->_allocator_type.construct(&_node->val, val);
        //         this->_last_node->parent = this->_node;
        //         this->_node->right = this->_last_node;
        //         iter = this->_node;
        //         return make_pair(iter, true);
        //     }
        //     else
        //     {
        //         TreeNode *new_node;
        //         TreeNode *root = _node;

        //         if (val.first <= _node->val.first)
        //         {
        //             while (root->left)
        //             {
        //                 root = root->left;
        //             }
        //             new_node = construct_tree_node(val);
        //             root->left = new_node;
        //             new_node->right = NULL;
        //             new_node->left = NULL;
        //             new_node->parent = root;
        //             iter = new_node;
        //         }
        //         else
        //         {
        //             while (root->right != _last_node)
        //             {
        //                 root = root->right;
        //             }
        //             if (root->val.first == val.first)
        //                 return (make_pair(iterator(root), false));
        //             new_node = construct_tree_node(val);
        //             root->right = new_node;
        //             new_node->left = NULL;
        //             new_node->right = _last_node;
        //             _last_node->parent = new_node;
        //             new_node->parent = root;
        //             iter = _last_node;
        //         }
        //         return make_pair(iter, true);
        //     }
        // }

        // then add balancing function !

        iterator
        insert(iterator position, const value_type &val);

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

        size_type _height(TreeNode *tmp, int i = 1)
        {
            int x;
            int y;
            if (tmp && tmp != _last_node)
            {
                if (tmp->left && tmp->right && tmp->right != _last_node)
                {
                    x = _height(tmp->left, i + 1);
                    y = _height(tmp->right, i + 1);
                    i = (x > y) ? x : y;
                }
                else if (tmp->left)
                    i = _height(tmp->left, i + 1);
                else if (tmp->right && tmp->right != _last_node)
                    i = _height(tmp->right, i + 1);
            }
            else
                return (0);

            return (i);
        }
        // A utility function to get maximum
        // of two integers
        int max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        int height(TreeNode *N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        }

        /* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
        TreeNode *newNode(const value_type &val, TreeNode *parent = NULL)
        {
            TreeNode *node;
            node = _alloc_node.allocate(1);
            _allocator_type.construct(&node->val, val);
            node->right = NULL;
            node->left = NULL;
            node->parent = parent;
            node->height = 1; // new node is initially
                              // added at leaf

            return (node);
        }

        // A utility function to right
        // rotate subtree rooted with y
        // See the diagram given above.
        TreeNode *rightRotate(TreeNode *y)
        {
            TreeNode *x = y->left;
            TreeNode *T2 = x->right;

            // Perform rotation

            x->right = y;
            y->left = T2;

            // Update parent pointers
            x->parent = y->parent;
            y->parent = x;
            if (T2)
                T2->parent = y;

            // Update heights
            y->height = max(height(y->left),
                            height(y->right)) +
                        1;
            x->height = max(height(x->left),
                            height(x->right)) +
                        1;

            // Return new root
            return x;
        }

        // A utility function to left
        // rotate subtree rooted with x
        // See the diagram given above.
        TreeNode *leftRotate(TreeNode *x)
        {
            TreeNode *y = x->right;
            TreeNode *T2 = y->left;

            // Perform rotation
            y->left = x;
            x->right = T2;

            // Update parent pointers

            y->parent = x->parent;
            x->parent = y;
            if (T2)
                T2->parent = x;

            // Update heights
            x->height = max(height(x->left),
                            height(x->right)) +
                        1;
            y->height = max(height(y->left),
                            height(y->right)) +
                        1;

            // Return new root
            return y;
        }

        // Get Balance factor of node N
        int getBalance(TreeNode *N)
        {
            if (N == NULL)
                return 0;
            return _height(N->left) - _height(N->right);
        }

        // Recursive function to insert a key
        // in the subtree rooted with node and
        // returns the new root of the subtree.
        TreeNode *insert_node(TreeNode *node, const value_type &val, TreeNode *parent = NULL)
        {
            if (node == NULL)
                return (newNode(val, parent)); // initially parent is set to NULL

            /* 1. Perform the normal BST insertion */

            if (val.first < node->val.first)
            {
                node->left = insert_node(node->left, val, node); // here we instead of NULL parent has the value
            }
            else if (val.first > node->val.first)
            {
                node->right = insert_node(node->right, val, node); // here we instead of NULL parent has the value
            }
            else // Equal keys are not allowed in BST
                return node;

            /* 2. Update height of this ancestor node */
            node->height = 1 + max(height(node->left),
                                   height(node->right));

            /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
            int balance = getBalance(node);

            // If this node becomes unbalanced, then
            // there are 4 cases

            // Left Left Case
            if (balance > 1 && val.first < node->left->val.first)
                return rightRotate(node);

            // Right Right Case
            if (balance < -1 && val.first > node->right->val.first)
                return leftRotate(node);

            // Left Right Case
            if (balance > 1 && val.first > node->left->val.first)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Right Left Case
            if (balance < -1 && val.first < node->right->val.first)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            /* return the (unchanged) node pointer */
            return node;
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

        TreeNode *max_node(TreeNode *node)
        {
            if (node)
            {
                while (node->right)
                    node = node->right;
            }
            return (node);
        }

        size_type tree_size(TreeNode *node) const
        {
            if (node == NULL || node->right == _last_node)
                return 0;
            return (tree_size(node->left) + 1 + tree_size(node->right));
        }

        /*      ----PRINT TREE----      */
        /** These methods are not included in the 
  *** container map. They can be used to 
  *** check the balance of a tree.
  **
  */
        void treeprint()
        {
            int i = 0;
            while (i <= _height(_node) - 1)
            {
                printlv(i);
                i++;
                std::cout << std::endl;
            }
        }

        void printlv(int n)
        {
            TreeNode *temp = _node;
            int val = pow(2, _height(_node) - n + 1);
            std::cout << std::setw(val) << "";
            dispLV(temp, n, val);
        }

        void dispLV(TreeNode *p, int lv, int d)
        {
            int disp = 2 * d;
            if (lv == 0)
            {
                if (p == NULL)
                {

                    std::cout << " x ";
                    std::cout << std::setw(disp - 3) << "";
                    return;
                }
                else
                {
                    // int result = ((p->data.first <= 1) ? 1 : log10(p->data.first) + 1);
                    std::cout << " " << p->val.first << " ";
                    std::cout << std::setw(disp - 3) << "";
                }
            }
            else
            {
                if (p == NULL && lv >= 1)
                {
                    dispLV(NULL, lv - 1, d);
                    dispLV(NULL, lv - 1, d);
                }
                else
                {
                    dispLV(p->left, lv - 1, d);
                    dispLV(p->right, lv - 1, d);
                }
            }
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