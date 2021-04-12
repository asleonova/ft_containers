/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:04:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/03/30 19:34:04 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "Iterator.hpp"

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
		typedef ft::iterator<T>     iterator;
		// TO DO : const_iterator, reverse iterator, const reverse iterator

		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		



		// а дальше надо создать итератор!!!
		// и потом еще некоторые параметры (которые дальше на сайте С++)

		/* 4 CONSTRUCTORS: */
			explicit vector(const allocator_type& alloc = allocator_type()) {} // #1: default constructor
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
		iterator begin();
		iterator 

		/* */
	};

}

#endif /* ***************************************************** MUTANTSTACK_H */