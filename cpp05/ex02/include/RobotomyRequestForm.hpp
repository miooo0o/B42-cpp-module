#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    RobotomyRequestForm(void);
    void    execute(Bureaucrat const &executor) const;

public:
    RobotomyRequestForm(std::string& target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
};