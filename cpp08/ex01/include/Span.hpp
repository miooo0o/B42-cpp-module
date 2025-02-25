#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span
{

private:
    std::vector<unsigned int>   _numbers;
    unsigned int                _storageLimit;
public:
    Span(const unsigned int storageLimit);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void            addNumber(const int number);
    unsigned int    shortestSpan() const;
    unsigned int    longestSpan() const;


private:
    Span();
};