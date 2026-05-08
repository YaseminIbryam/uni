// Напишете шаблон на функция filter, която приема масив от тип T и функция, която приема аргумент от тип T и връща резултат от тип bool. Функцията filter да връща нов масив, съставен от тези елементи от подадения масив, върху които като приложим подадената функция, получаваме резултат true.

#include <iostream>
#include "template.h"

template <typename T>
T* filter(T* begin, T* end,UnaryOperation<T,bool> f)
{
    T* p = begin;
    while(begin != end)
    {
        if(f(*begin)){
            *p++ = *begin;
        }
        ++begin;
    }
    return p;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int *end = filter<int>(std::begin(arr), std::end(arr), [](int element)
                           { return element % 2 == 0; });
    print(std::begin(arr), end); // -> 2 4
}
