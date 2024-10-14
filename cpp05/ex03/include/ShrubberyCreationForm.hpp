/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:27:47 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 18:00:33 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <fstream>

class ShrubberyCreationForm: public Form
{
private:
    std::string _target;
    
    ShrubberyCreationForm();
    void    beExecute(Bureaucrat const &executor) const;

    class FileOpenException : public std::exception
    {
        virtual const char* what() const throw();
    };

protected:
public:
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
};