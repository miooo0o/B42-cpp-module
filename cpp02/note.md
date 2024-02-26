### `this` pointer
this is a special keyword in C++ that represents a pointer to the current object. *this is used to dereference the pointer, representing the actual current object. It's commonly used when there is a need to distinguish between a member variable and a parameter with the same name in a member function or when passing the current object to another function.

### Description of the module
- Completed the `Fixed` class that takes floating-point numbers and integers as parameters and converts them to fixed-point numbers.
- The class can also be reconverted and returned via object functions.

### When do I need to convert floating point to fixed point?
1. Hardware Limitations:
In certain embedded systems or specific environments, supporting floating-point operations or data types may be challenging. Using fixed-point representation can be more efficient in terms of memory and computational resources than using floating-point.
2. Precision Control:
Fixed-point allows direct control over the number of bits dedicated to the fractional part, enabling precise control over the precision of operations. This can be advantageous when specific precision requirements need to be met.

**note**: Games often use fixed points, but I'll have to look into why.

### Inside class definition or Outside class definition?
- It is common practice to define the `operator<<` outside of the class. This function is responsible for the output of the class, and should typically be defined outside of the class. Defining it externally in this way provides a clearer separation between the interface of the class and the output operations.

### pre-increment and post-increment

1. pre-increment
: Increments the current value and returns the incremented value

```cpp
Fixed& operator++()
{
    _value++;
    return (*this);
}
```

2. post-increment
: Returns the current value, then increments it

```cpp
Fixed operator++(int)
{
    Fixed tmp(*this);
    _value++;
    return (tmp);
}
```