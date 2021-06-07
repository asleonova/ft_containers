/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:16:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/06/07 13:28:25 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>

namespace ft
{

    template <class T, class Container = std::deque<T> >
    class queue
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    private:
        container_type cont;

    public:
        explicit queue(const container_type &ctnr = container_type()) : cont(ctnr) {}

        bool empty() const
        {
            cont.empty();
        }

        size_type size() const
        {
            cont.size();
        }

        value_type &front()
        {
            cont.front();
        }

        const value_type &front() const
        {
            cont.front();
        }

        value_type &back()
        {
            cont.back();
        }

        const value_type &back() const
        {
            cont.back();
        }

        void push(const value_type &val)
        {
            cont.push_back(val);
        }

        void pop()
        {
            cont.pop();
        }

        template <class T_, class Container_>
        friend bool
        operator==(const queue<T_, Container_> &lhs, const queue<T_, Container_> &rhs);

        template <class T_, class Container_>
        friend bool
        operator!=(const queue<T_, Container_> &lhs, const queue<T_, Container_> &rhs);

        template <class T_, class Container_>
        friend bool
        operator<(const queue<T_, Container_> &lhs, const queue<T_, Container_> &rhs);

        template <class T_, class Container_>
        friend bool
        operator<=(const queue<T_, Container_> &lhs, const queue<T_, Container_> &rhs);

        template <class T_, class Container_>
        friend bool
        operator>(const queue<T_, Container_> &lhs, const queue<T_, Container_> &rhs);

        template <class T_, class Container_>
        friend bool
        operator>=(const queue<T_, Container_> &lhs, const queue<T_, Container_> &rhs);
    };

    /*================================ NON-MEMBER OVERLOADS: ================================*/

     
    template <class T, class Container>
    bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return (lhs.cont == rhs.cont);
    }

    template <class T, class Container>
    bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return (lhs.cont != rhs.cont);
    }

    template <class T, class Container>
    bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return (lhs.cont < rhs.cont);
    }

    template <class T, class Container>
    bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return (lhs.cont <= rhs.cont);
    }

    template <class T, class Container>
    bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return (lhs.cont > rhs.cont);
    }

    template <class T, class Container>
    bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return (lhs.cont >= rhs.cont);
    }
}

#endif