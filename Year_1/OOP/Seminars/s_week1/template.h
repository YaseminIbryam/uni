#include <iostream>

template <typename T, typename U>
using UnaryOperation = U (*)(T);

template <typename T, typename U, typename S>
using BinaryOperation = S (*)(T, U);

template <typename T>
void print(T begin, T end)
{
    while (begin != end)
    {
        std::cout << *begin++ << " ";
    }
}

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}