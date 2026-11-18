#include <iostream>

using namespace std;

//Задача 2: Да се напише функция, която приема масив от цели числа и връща средната стойност на елементите му.
double average(const int arr[], size_t size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double average = sum / size;
    return average;
}

int main()
{
    const int N = 4;
    int arr[N] = { 5, 7, 4, 9 };
    cout << average(arr, N);
}