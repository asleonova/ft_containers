/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:04:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/19 13:59:36 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "Iterator.hpp"
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

		// а дальше надо создать итератор!!!
		// и потом еще некоторые параметры (которые дальше на сайте С++)

		/* 4 CONSTRUCTORS: */
		explicit vector(const allocator_type &alloc = allocator_type()) : _allocator_type(alloc), _capacity(NULL), _v_begin(NULL), _v_end(NULL) {} // #1: default constructor
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type()) {} // #2: fill constructor: constructs a container with n elements. Each element is a copy of val.
		/* #3: Constructs a container with as many elements as the range [first,last), 
			with each element constructed from its corresponding element in that range, in the same order. */
		/*!!!!!!доделать*/

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type()) {}

		/* #4: copy constructor: */
		explicit vector(vector const &src);

		/* DESTRUCTOR */
		~vector() { this->_allocator_type.deallocate(this->_v_begin, size());
		}

		/*ASSIGNMENT OPERATOR*/

		vector &operator=(vector const &rhs) {}

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

		reference front() { return *(this->_v_begin); }
		const_reference front() const { return *(this->_v_begin); }
		reference back() { return *(this->_v_end - 1); }
		const_reference back() const { return *(this->_v_end - 1); }
		size_type size() const { return static_cast<size_type>(this->_v_end - this->_v_begin); }

		size_t max_size(void) const
		{
			return this->_allocator_type.max_size();
		}

		// Resizes the container so that it contains n elements.

		void resize(size_type n, value_type val = value_type())
		{
			if (this->_v_size > n)
			{
				erase(begin() + n, end());
			}
			if (this->_v_size < n)
			{
				size_type offset;
				offset = n - this->_v_size;
				insert(end(), offset, val);
			}
		}

		void reserve(size_type n)
		{
			// If n is greater than the current vector capacity,
			// the function causes the container to reallocate its storage increasing its capacity to n (or greater).
			if (n < capacity())
				return;
			//pointer val = this->_v_begin;
			//pointer array = this->_allocator_type.allocate(n);
			if (n > capacity())
			{
				pointer old_begin = this->_v_begin;
				pointer old_end = this->_v_end;
				//size_type old_size = size();
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

			
		//	this->_v_end = _v_begin + n;
		}

					// 		m_begin = arr;
					// m_end = m_begin + len;
					// m_end_capacity = m_begin + n

					// len - it's size() // arr - it's allocate n objects

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

		iterator erase(iterator position)
		{
			pointer ptr_pos = &(*position);
			this->_allocator_type.destroy(&(*position));
			//if (ptr_pos + 1 == this->_v_end - 1)
				//this->_allocator_type.destroy(ptr_pos);
			for (int i = 0; i < this->_v_end - ptr_pos - 1; i++)
			{
				this->_allocator_type.construct(ptr_pos + i, *(ptr_pos + i + 1)); // put the right side of the array to the place pointed by the destroyed element;
				this->_allocator_type.destroy(ptr_pos + i + 1); // destroy the duplicate
			}
			this->_v_end--;
			return (iterator(ptr_pos));
		}

		iterator erase(iterator first, iterator last)
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
				this->_allocator_type.destroy(ptr_last + i); // destroy the copied element
			}
			this->_v_end -= ptr_last - ptr_first;
			return (iterator(ptr_first));
		}

		iterator insert(iterator position, const value_type &val)
		{
			
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
		}

		void assign(size_type n, const value_type &val)
		{
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

		/* */
	private:
		pointer _capacity;
		pointer _v_begin;
		pointer _v_end;
		allocator_type _allocator_type;
	};

}

#endif /* ***************************************************** MUTANTSTACK_H */