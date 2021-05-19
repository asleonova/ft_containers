/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:59:09 by dbliss            #+#    #+#             */
/*   Updated: 2021/05/19 14:57:54 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>

namespace ft
{
    template <class T>
    void swap(T &a, T &b)
    {
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    	template<class T>
		inline const T&
		max(const T &a, const T &b)
		{
			return (a > b ? a : b);
		}

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2)) // or: if (!pred(*first1,*first2)), for version 2
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template <class T>
    struct less
    {
    public:
        bool
        operator()(const T &lhs, const T &rhs) const
        {
            return (lhs < rhs);
        }
    };
}

#endif