/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:04:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/05 18:58:04 by dbliss           ###   ########.fr       */
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
		typedef ft::iterator<pointer>     myIterator;
		typedef ft::iterator<const pointer> const_iterator;
		// TO DO :  reverse iterator, const reverse iterator

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

		myIterator begin() { return (myIterator(&(front()))); } // тут мы получаем ссылку из указателя (фронт возвращает указатель, и подставляем в конструктор)
		
		myIterator end() { return myIterator(&(back()) + 1); } // Unlike member vector::end, which returns an myIterator just past this element, this function returns a direct reference, поэтому +1 

		const_iterator begin() const { return const_iterator(&(front())); }
		
		const_iterator end() const { return const_iterator(&(back()) + 1); }
		
		//reverse_iterator rbegin();
		//reverse_iterator rend();
		//const_reverse_iterator rbegin();
		//const_reverse_iterator rend();

		reference front() { return *_v_begin; }
		const_reference front() const { return *_v_begin; }
		reference back() { return *(this->_v_end - 1); }
		const_reference back() const { return *(this->_v_end_ - 1); }
		size_type size() const { return this->_v_size; }

		/* */

		private:

			pointer _v_begin;
			pointer _v_end;
			size_t _v_size;
	};

}

#endif /* ***************************************************** MUTANTSTACK_H */