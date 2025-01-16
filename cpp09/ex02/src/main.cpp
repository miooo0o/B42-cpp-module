/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:25:45 by minakim           #+#    #+#             */
/*   Updated: 2025/01/16 13:14:57 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Validate.hpp"
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try
    {
        Validate    validate(argc, argv);

        if (!validate.isValidate())
            return (1); /* err msg */

        PmergeMe guriMergeMe(validate.getElements(), validate.getCount());
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       
}