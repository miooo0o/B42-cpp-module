/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:25:45 by minakim           #+#    #+#             */
/*   Updated: 2025/02/03 15:29:55 by minakim          ###   ########.fr       */
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
        
        // check if not validate
        if (!validate.validated())
            return (1);

        PmergeMe    guri(validate.getElements());

    }
    catch(const std::exception& e)
    {
        std::cerr << "error: " << e.what() << '\n';
        return (1);
    }
       
}