/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:25:45 by minakim           #+#    #+#             */
/*   Updated: 2025/01/29 16:32:16 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Validate.hpp"
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try
    {
        Validate    validate(argc, argv);        

        // test
        validate.print();

        if (!validate.validated())
            return (1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "error: " << e.what() << '\n';
        return (1);
    }
       
}