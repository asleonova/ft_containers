/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:17:09 by dbliss            #+#    #+#             */
/*   Updated: 2021/03/31 20:18:37 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

int main()
{
    ft::vector<int>::iterator it;
    ft::vector<int> v1(4);
    v1.begin();
    std::cout << std::vector<int>::value_type << std::endl;
    return 0;
}