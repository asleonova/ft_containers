/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:53:27 by dbliss            #+#    #+#             */
/*   Updated: 2021/06/07 11:11:55 by dbliss           ###   ########.fr       */
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

        private:
            container_type cont;

        public:
            
            explicit stack (const container_type& ctnr = container_type()) : cont(cntr) {}
            
            bool empty() const
            {
                return cont.empty();
            }

            size_type size() const
            {
                return cont.size();
            }

            value_type& top()
            {
                return cont.back();
            }
            
            const value_type& top() const
            {
                return cont.back();
            }

            void push (const value_type& val)
            {
                return cont.push_back();
            }

            void pop()
            {
                return cont.pop_back();
            }
    };

     /*================================ NON-MEMBER OVERLOADS: ================================*/

     
    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        
    }

    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

#endif