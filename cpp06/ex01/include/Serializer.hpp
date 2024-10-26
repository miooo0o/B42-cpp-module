/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:17:46 by minakim           #+#    #+#             */
/*   Updated: 2024/10/26 13:19:21 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

struct Data
{
    std::string name;
    int         rank;

    Data(std::string const& name, int rank) : name(name), rank(rank) {}
};

class Serializer
{
public:
    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);

private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);

};
