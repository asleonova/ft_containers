/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:53:27 by dbliss            #+#    #+#             */
/*   Updated: 2021/06/07 11:01:25 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "List.hpp"

namespace ft
{
    template <class T, class Container = list<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

            explicit stack (const container_type& ctnr = container_type());
            
            


    };
}

#endif