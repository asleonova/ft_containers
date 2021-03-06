/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:16:34 by dbliss            #+#    #+#             */
/*   Updated: 2021/06/07 13:53:15 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>

namespace ft
{
    	template<class T, class Container = deque<T> >
		class queue
		{
			public:
				/** The first template parameter (T) */
				typedef T value_type;

				/** The second template parameter (Container) */
				typedef Container container_type;

				/** An unsigned integral type */
				typedef size_t size_type;

			private:
				container_type m_container;

			public:
				/**
				 * Constructs a queue container adaptor object.
				 *
				 * @param ctnr Container object.
				 */
				explicit
				Queue(const container_type &ctnr = container_type()) :
						m_container(ctnr)
				{
				}

				/**
				 * Returns whether the queue is empty: i.e. whether its size is zero.
				 * This member function effectively calls member empty of the underlying container object.
				 *
				 * @return true if the underlying container's size is 0, false otherwise.
				 */
				bool
				empty(void) const
				{
					return (m_container.empty());
				}

				/**
				 * Returns the number of elements in the queue.
				 * This member function effectively calls member size of the underlying container object.
				 *
				 * @return The number of elements in the underlying container.
				 */
				size_type
				size(void) const
				{
					return (m_container.size());
				}

				/**
				 * Returns a reference to the next element in the queue.
				 * The next element is the "oldest" element in the queue and the same element that is popped out from the queue when ::pop is called.
				 * This member function effectively calls member front of the underlying container object.
				 *
				 * @return A reference to the next element in the queue.
				 */
				value_type&
				front()
				{
					return (m_container.front());
				}

				/**
				 * Returns a reference to the next element in the queue.
				 * The next element is the "oldest" element in the queue and the same element that is popped out from the queue when ::pop is called.
				 * This member function effectively calls member front of the underlying container object.
				 *
				 * @return A const-qualified reference to the next element in the queue.
				 */
				const value_type&
				front() const
				{
					return (m_container.front());
				}

				/**
				 * Returns a reference to the last element in the queue. This is the "newest" element in the queue (i.e. the last element pushed into the queue).
				 * This member function effectively calls member back of the underlying container object.
				 *
				 * @return A reference to the last element in the queue.
				 */
				value_type&
				back()
				{
					return (m_container.back());
				}

				/**
				 * Returns a reference to the last element in the queue. This is the "newest" element in the queue (i.e. the last element pushed into the queue).
				 * This member function effectively calls member back of the underlying container object.
				 *
				 * @return A const-qualified reference to the last element in the queue.
				 */
				const value_type&
				back() const
				{
					return (m_container.back());
				}

				/**
				 * Inserts a new element at the end of the queue, after its current last element. The content of this new element is initialized to val.
				 * This member function effectively calls the member function push_back of the underlying container object.
				 *
				 * @param val Value to which the inserted element is initialized.
				 */
				void
				push(const value_type &val)
				{
					m_container.push_back(val);
				}

				/**
				 * Removes the next element in the queue, effectively reducing its size by one.
				 * The element removed is the "oldest" element in the queue whose value can be retrieved by calling member ::front.
				 * This calls the removed element's destructor.
				 * This member function effectively calls the member function pop_front of the underlying container object.
				 */
				void
				pop(void)
				{
					m_container.pop_front();
				}


    // template <class T, class Container = std::deque<T> >
    // class queue
    // {
    // public:
    //     typedef T value_type;
    //     typedef Container container_type;
    //     typedef size_t size_type;

    // private:
    //     container_type cont;

    // public:
    //     explicit queue(const container_type &ctnr = container_type()) : cont(ctnr) {}

    //     bool empty() const
    //     {
    //         return cont.empty();
    //     }

    //     size_type size() const
    //     {
    //         return cont.size();
    //     }

    //     value_type &front()
    //     {
    //         return cont.front();
    //     }

    //     const value_type &front() const
    //     {
    //         return cont.front();
    //     }

    //     value_type &back()
    //     {
    //         return cont.back();
    //     }

    //     const value_type &back() const
    //     {
    //         return cont.back();
    //     }

    //     void push(const value_type &val)
    //     {
    //         cont.push_back(val);
    //     }

    //     void pop()
    //     {
    //         cont.pop_back();
    //     }

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