// Напишете шаблон на функция print, която приема масив и извежда елементите на масива на стандартния изход.
#include <iostream>

template <typename T>
void print(T begin, T end)
{
    while(begin != end)
    {
        std::cout << *begin++ << " ";
    }
}


int main(){
    int arr[] = {1, 2, 3, 4};
    print(std::begin(arr), std::end(arr));
}