/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:16:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/06/07 13:23:18 by dbliss           ###   ########.fr       */
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
        explicit queue(const container_type &ctnr = container_type());
        bool empty() const;
        size_type size() const;
        value_type &front();
        const value_type &front() const;
        value_type &back();
        const value_type &back() const;
        void push(const value_type &val);
        void pop();

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
}

#endif