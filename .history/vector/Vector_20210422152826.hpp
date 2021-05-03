/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:04:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/22 15:28:26 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "Iterator.hpp"
#include "Algorithm.hpp"
#include "Identifiers.hpp"

#include "stddef.h"

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef ft::myIterator<pointer> iterator;
		typedef ft::myIterator<const_pointer> const_iterator;
		typedef ft::myReverse_iterator<iterator> reverse_iterator;
		typedef ft::myReverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		/* 4 CONSTRUCTORS: */

		// #1: default constructor
		explicit vector(const allocator_type &alloc = allocator_type()) : _allocator_type(alloc), _capacity(NULL), _v_begin(NULL), _v_end(NULL) {}

		// #2: fill constructor: constructs a container with n elements. Each element is a copy of val.
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type()) : _allocator_type(alloc), _capacity(NULL), _v_begin(NULL), _v_end(NULL)
		{
			if (n)
				assign(n, val);
		}

		/* #3: Constructs a container with as many elements as the range [first,last), 
			with each element constructed from its corresponding element in that range, in the same order. */

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL, const allocator_type &alloc = allocator_type()) : _allocator_type(alloc), _capacity(NULL), _v_begin(NULL), _v_end(NULL)
		{
			assign(first, last);
		}

		//#4: copy constructor: */
		// vector(const vector &src) : _v_begin(NULL), _v_end(NULL), _capacity(NULL)
		// {
		// 	this->_allocator_type = src._allocator_type;
		// 	operator=(src);
		//}

		/* DESTRUCTOR */
		~vector()
		{
			if (this->_v_begin)
			{
				clear();
				this->_allocator_type.deallocate(this->_v_begin, capacity());
				this->_v_begin = NULL;
				this->_v_end = NULL;
				this->_capacity = NULL;
			}
		}
		/*ASSIGNMENT OPERATOR*/

		vector &operator=(vector const &rhs)
		{
			if (this != &rhs)
			{
				assign(rhs.begin(), rhs.end());
			}
			return (*this);
		}

		/* ITERATORS */

		iterator begin() { return (iterator(&(front()))); } // тут мы получаем ссылку из указателя (фронт возвращает указатель, и подставляем в конструктор)

		iterator end() { return iterator(&(back()) + 1); } // Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference, поэтому +1

		const_iterator begin() const { return const_iterator(&(front())); }

		const_iterator end() const { return const_iterator(&(back()) + 1); }

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		/* CAPACITY */

		size_type size() const { return static_cast<size_type>(this->_v_end - this->_v_begin); }

		size_t max_size(void) const
		{
			return this->_allocator_type.max_size();
		}

		// Resizes the container so that it contains n elements.
		void resize(size_type n, value_type val = value_type())
		{
			size_type v_size = size();
			if (n < v_size)
			{
				erase(begin() + n, end());
			}
			else if (v_size < n)
			{
				size_type offset;
				offset = n - v_size;
				insert(end(), offset, val);
			}
		}

		size_type capacity() const
		{
			return static_cast<size_type>(this->_capacity - this->_v_begin);
		}

		bool empty() const
		{
			if (size() == 0)
				return true;
			else
				return false;
		}

		void reserve(size_type n)
		{
			// If n is greater than the current vector capacity,
			// the function causes the container to reallocate its storage increasing its capacity to n (or greater).
			if (n < capacity())
				return;
			if (n > capacity())
			{
				pointer old_begin = this->_v_begin;
				pointer old_end = this->_v_end;
				size_type old_capacity = capacity();

				pointer array = _allocator_type.allocate(n); // allocate enough space for n objects
				this->_v_end = array;
				while (this->_v_begin != old_end) // copy all previous content to the new array
				{
					_allocator_type.construct(this->_v_end, *(this->_v_begin)); // construct objects
					this->_v_end++;
					this->_v_begin++;
				}
				_allocator_type.deallocate(old_begin, old_capacity);
				this->_v_begin = array;
				this->_capacity = this->_v_begin + n; // extend the capacity ??? //check this
			}
		}

		/* ELEMENT ACCESS */

		reference operator[](size_type n)
		{
			return this->_v_begin[n];
		}

		const_reference operator[](size_type n) const
		{
			return this->_v_begin[n];
		}

		reference at(size_type n)
		{
			if (n < 0 || n > size())
				throw(std::out_of_range("error: std::out_of_range"));
			return (this->_v_begin[n]);
		}

		const_reference at(size_type n) const
		{
			if (n < 0 || n > size())
				throw(std::out_of_range("error: std::out_of_range"));
			return this->_v_begin[n];
		}

		reference front() { return *(this->_v_begin); }

		const_reference front() const { return *(this->_v_begin); }

		reference back() { return *(this->_v_end - 1); }

		const_reference back() const { return *(this->_v_end - 1); }

		/* MODIFIERS */

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIterator = InputIterator())
		{
			(void)isIterator;
			clear();
			insert(begin(), first, last);
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			insert(begin(), n, val);
		}

		// Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
		// If size < capacity, a push_back simply puts the new element at the end and increments the size by 1.
		void push_back(const value_type &val)
		{
			if (this->_v_end == this->_capacity)
			{
				size_type reserve_cap = capacity();
				reserve(2 * reserve_cap + 1);
			}
			_allocator_type.construct(this->_v_end, val);
			this->_v_end++;
		}

		// Removes the last element in the vector, effectively reducing the container size by one.
		// If the container is not empty, the function never throws exceptions (no-throw guarantee).
		// Otherwise, it causes undefined behavior.

		void pop_back()
		{
			this->_allocator_type.destroy(&back());
			this->_v_end--;
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type len = /*static_cast<size_type>*/ (&(*position)) - this->_v_begin;

			if (capacity() >= n + size())
			{
				for (size_type i = 0; i < size() - len; i++) // size - len it's the nums of elem aftern n to move
					this->_allocator_type.construct(this->_v_end - i + (n - 1), *(this->_v_end - i - 1));
				//this->_allocator_type.construct(&(*position) + n + i, *(position + i)); // moving the rest of the array after 'n' to new positions
				this->_v_end += n;
				while (n != 0)
				{
					this->_allocator_type.construct(&(*position) + (n - 1), val); // filling from the "end"
					n--;
				}
			}
			else
			{
				reserve(size() * 2 + n);
				for (size_type i = 0; i < this->size() - len; i++)
					this->_allocator_type.construct(this->_v_end - i + (n - 1), *(this->_v_end - i - 1)); // creating elements followed after the inserted elements
				this->_v_end += n;
				size_type i = len;
				for (int j = 0; j < n; j++, i++)
				{
					this->_allocator_type.construct(this->_v_begin + i, val); // creating the inserted elements
				}
			}
		}

		iterator insert(iterator position, const value_type &val)
		{
			difference_type offset = position - begin();
			insert(position, 1, val);
			return (iterator(begin() + offset));
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIterator = InputIterator())
		{
			(void)isIterator;
			size_type len = /*static_cast<size_type>*/ (&(*position)) - this->_v_begin;
			difference_type diff = ft::distance(first, last);
			if (capacity() >= diff + size())
			{
				for (size_type i = 0; i < size() - len; i++)
					this->_allocator_type.construct(this->_v_end - i + (diff - 1), *(this->_v_end - i - 1)); // moving the rest of the array after 'n' to new positions
				this->_v_end += diff;
				for (int i = 0; i < diff; ++i)
				{
					this->_allocator_type.construct(&(*position) + i, *first);
					first++;
				}
			}
			else
			{
				reserve(size() * 2 + diff);
				for (size_type i = 0; i < this->size() - len; i++)
					this->_allocator_type.construct(this->_v_end - i + (diff - 1), *(this->_v_end - i - 1)); // creating elements followed after the inserted elements
				this->_v_end += diff;
				size_type i = len;
				for (int j = 0; j < diff; j++, i++, first++)
				{
					this->_allocator_type.construct(this->_v_begin + i, *first); // creating the inserted elements
				}
			}
		}

		iterator erase(iterator position) // returns iterator of the end
		{
			pointer ptr_pos = &(*position);
			this->_allocator_type.destroy(&(*position));
			//if (ptr_pos + 1 == this->_v_end - 1)
			//this->_allocator_type.destroy(ptr_pos);
			for (int i = 0; i < this->_v_end - ptr_pos - 1; i++)
			{
				this->_allocator_type.construct(ptr_pos + i, *(ptr_pos + i + 1)); // put the right side of the array to the place pointed by the destroyed element;
				this->_allocator_type.destroy(ptr_pos + i + 1);					  // destroy the duplicate
			}
			this->_v_end--;
			return (iterator(ptr_pos));
		}

		iterator erase(iterator first, iterator last) // returns iterator to the place of the first erased element
		{
			pointer ptr_first = &(*first);
			pointer ptr_last = &(*last);

			while (&(*first) != &(*last))
			{
				this->_allocator_type.destroy(&(*first)); // delete the ranged elements
				first++;
			}
			for (int i = 0; i < this->_v_end - ptr_last; i++)
			{
				this->_allocator_type.construct(ptr_first + i, *(ptr_last + i)); // copy the contents of the array to the place of deleted elements
				this->_allocator_type.destroy(ptr_last + i);					 // destroy the copied element
			}
			this->_v_end -= ptr_last - ptr_first;
			return (iterator(ptr_first));
		}

		void swap(vector &x)
		{
			if (this == &x)
				return;
			ft::swap(this->_v_begin, x._v_begin);
			ft::swap(this->_v_end, x._v_end);
			ft::swap(this->_capacity, x._capacity);
		}

		void clear()
		{
			size_type v_size = size();
			for (size_type i = 0; i < v_size; i++)
			{
				this->_allocator_type.destroy(this->_v_end--);
			}
		}

	private:
		pointer _capacity;
		pointer _v_begin;
		pointer _v_end;
		allocator_type _allocator_type;
	};

	/* NON-MEMBER FUNCTION OVERLOADS: */

	/* RELATIONAL OPERATORS */

	/* The equality comparison (operator==) is performed by first comparing sizes, and if they match,
	** the elements are compared sequentially using operator==,
	** stopping at the first mismatch (as if using algorithm equal).
	*/

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	// a<=b	equivalent !(b<a)
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	// a>b	equivalent to b<a
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	// a>=b	equivalent !(a<b)
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	/* SWAP */
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.ft::swap(y);
	}
}

#endif /* ***************************************************** MUTANTSTACK_H */