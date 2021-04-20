/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:59:09 by dbliss            #+#    #+#             */
/*   Updated: 2021/04/20 17:00:50 by dbliss           ###   ########.fr       */
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
}

#endif