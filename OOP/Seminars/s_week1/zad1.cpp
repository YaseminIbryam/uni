// Напишете шаблон на функция is_fixed_point, която приема аргумент от тип T и функция на 1 аргумент от тип T. Функцията is_fixed_point да проверява дали подаденият аргумент е неподвижна точка на подадената функция (x е неподвижна точка на f, ако f(x) = x).

#include <iostream>

template <typename T>
bool is_fixed_point(T (*f)(T), T x)
{
    return f(x) == x;
}

int main()
{
    std::cout << std::boolalpha << is_fixed_point<int>([](int n){ return n * 5;}, 0) << '\n'; // -> true
std::cout << std::boolalpha << is_fixed_point<int>([](int n){ return n * 5;}, 2) << '\n'; // -> false
}
