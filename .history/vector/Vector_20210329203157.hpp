/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:04:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/03/29 20:31:56 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		

		/* 4 CONSTRUCTORS: */
			explicit vector(const allocator_type& alloc = allocator_type()); // #1: default constructor
			explicit vector(size_type n, const value_type& val = value_type(), \
                 const allocator_type& alloc = allocator_type()) // #2: fill constructor: constructs a container with n elements. Each element is a copy of val.
			/* #3: Constructs a container with as many elements as the range [first,last), 
			with each element constructed from its corresponding element in that range, in the same order. */
			template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
				 /* #4: copy constructor: */
			explicit vector(vector const &src);
						
		/* DESTRUCTOR */	
			~vector();

		/*ASSIGNMENT OPERATOR*/

		vector &operator=(vector const &rhs);

		/* */
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		const_iterator cbegin() { return std::stack<T>::c.cbegin(); }
		const_iterator cend() { return std::stack<T>::c.cend(); }
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
		reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
		reverse_iterator rend() { return std::stack<T>::c.rend(); }
		const_reverse_iterator crbegin() { return std::stack<T>::c.crbegin(); }
		const_reverse_iterator crend() { return std::stack<T>::c.crend(); }

	private:
	};

	template <typename T>
	MutantStack<T>::MutantStack()
	{
	}

	template <typename T>
	MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
	{
	}

	template <typename T>
	MutantStack<T>::~MutantStack()
	{
	}

	template <typename T>
	MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
		{
			std::stack<T>::operator=(rhs);
		}
		return (*this);
	}

}

#endif /* ***************************************************** MUTANTSTACK_H */