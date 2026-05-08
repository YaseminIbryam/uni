//Напишете шаблон функция map, която приема масив от тип T и функция, която приема аргумент от тип T и връща резултат от тип U.Функцията map да връща нов масив, съставен от елементите на подадения масив след прилагането на подадената функция над тях.
#include <iostream>
#include "template.h"



template <typename T>
void map(T* begin, T* end, UnaryOperation<T, T> f)
{
    while(begin != end)
    {
        *begin = f(*begin);
        ++begin;
    }
}



int main(){
    int arr[] = {1, 2, 3, 4, 5};
    map<int>(std::begin(arr), std::end(arr), [](int element)
    { return element * element; });
    print(std::begin(arr), std::end(arr)); // -> 1 4 9 16 25
}