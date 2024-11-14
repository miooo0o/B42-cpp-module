/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:17:19 by minakim           #+#    #+#             */
/*   Updated: 2024/11/14 16:17:20 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma

#include <iostream>
#include <string>

template <typename T>
void    swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T       min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
T       max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}