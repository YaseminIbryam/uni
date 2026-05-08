// Напишете шаблон на функция sort_by, която приема функция cmp на 2 аргумента от тип T, която връща стойност от тип bool и масив от елементи от тип T. Функцията sort_by да сортира масива, като вместо < да ползва cmp за сравнение на елементите.
#include <iostream>
#include "template.h"
template <typename T>
void sort_by(BinaryOperation<T,T,bool> f, T* begin, T* end){
    size_t size = end - begin;
    for(size_t i = 0; i < size; i++){
        for (T* j = begin; j < end - i - 1; j++){
            if (f(*j, *( j + 1)) == 0)
            swap<T>(*j, *(j + 1));
        }
    }
}
// template <typename T>
// void sort_by(BinaryOperation<T, T, bool> f, T *begin, T *end)
// {
//     size_t size = end - begin;
//     for (size_t i = 0; i < size; i++)
//     {
//         for (size_t j = 0; j < size - 1; j++)
//         {
//             if (f(begin[j], begin[j + 1]) == 0)
//                 swap<T>(begin[j], begin[j + 1]);
//         }
//     }
// }


int main(){
    int arr[] = {1, 2, 3, 4, 5};
    sort_by<int>([](int a, int b)
                 { return a <= b; }, std::begin(arr), std::end(arr));

    print(std::begin(arr), std::end(arr)); // -> 1 2 3 4 5

    sort_by<int>([](int a, int b)
                 { return a > b; }, std::begin(arr), std::end(arr));

    print(std::begin(arr), std::end(arr)); // -> 5 4 3 2 1
}