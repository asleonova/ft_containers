/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:04:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/12 20:54:58 by dbliss           ###   ########.fr       */
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
		typedef ft::myIterator<pointer>     iterator;
		typedef ft::myIterator<const_pointer> const_iterator;
		typedef ft::myReverse_iterator<iterator> reverse_iterator;
		typedef ft::myReverse_iterator<const_iterator> const_reverse_iterator;
		
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		
		

		// а дальше надо создать итератор!!!
		// и потом еще некоторые параметры (которые дальше на сайте С++)

		/* 4 CONSTRUCTORS: */
			explicit vector(const allocator_type& alloc = allocator_type()) : _v_begin(NULL), _v_size(0) {} // #1: default constructor
			explicit vector(size_type n, const value_type& val = value_type(), \
                 const allocator_type& alloc = allocator_type()) {} // #2: fill constructor: constructs a container with n elements. Each element is a copy of val.
			/* #3: Constructs a container with as many elements as the range [first,last), 
			with each element constructed from its corresponding element in that range, in the same order. */
		/*!!!!!!доделать*/	
		
		
		
			template <class InputIterator>
        	 	vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type()) {}
				 
				 /* #4: copy constructor: */
			explicit vector(vector const &src);
						
		/* DESTRUCTOR */	
			~vector(){}

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
		
		const_reverse_iterator rbegin()
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend()
		{
			return const_reverse_iterator(begin());
		}


		reference front() { return *_v_begin; }
		const_reference front() const { return *_v_begin; }
		reference back() { return *(this->_v_end - 1); }
		const_reference back() const { return *(this->_v_end_ - 1); }
		size_type size() const { return this->_v_size; }

		iterator insert (iterator position, const value_type& val)
		{

		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			
		}

		template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
		{

		}
		
		template <class InputIterator>
  			void assign (InputIterator first, InputIterator last)
		{

		}

		void assign (size_type n, const value_type& val)
		{

		}

		size_type capacity() const
		{
			
		}

		/* */

		private:

			pointer _v_begin;
			pointer _v_end;
			size_t _v_size;
	};

}

#endif /* ***************************************************** MUTANTSTACK_H */