// Напишете функция filter, която приема масив от произволен тип, както и булева функция с единствен параметър от същия тип f(x). Функцията да връща указател към динамично заделен масив, в който се съдържат само елементите на масива, за които f(x) е 'истина'. Размерът на върнатия масив да се връща чрез презаписване на стойността на аргумента retSize
#include <iostream>

template <typename T>
T* filter(T *arr, size_t size, bool(*f)(T), size_t &retSize)
{
    T *result = new T[size];
    T* p = result;
    for(size_t i = 0; i < size; i++)
    {
        if(f(arr[i]))
        {
            *p++ = arr[i];
            
        }
    }
    retSize = p - result;
    return result;
}


int main(){
    int arr[6]{1, 2, 3, 4, 5, 6};
    size_t newSize = 0;
    int *p = filter<int>(arr, 6, [](int x){ return x % 2 == 0;}, newSize);
    for (size_t i = 0; i < newSize; i++)
    {
        std::cout << p[i] << " ";
    }

    delete[] p;
}