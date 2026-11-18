#include <iostream>
using namespace std;

//Задача 3: Да се напишат функции, които приемат масив от цели числа и връщат минималното и максималното число в масива.

int findMinInArr(const int arr[], size_t size)
{
    int n = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < n)
        {
            n = arr[i];
        }
    }
    return n;
}

int findMaxInArr(const int arr[], size_t size)
{
    int n = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > n)
        {
            n = arr[i];
        }
    }
    return n;
}

int main()
{
    const int N = 9;
    int arr[N] = { 3, 1, 2, 8, 13, 5, 1, 6, 25 };
    cout << findMinInArr(arr, N) << endl;
    cout << findMaxInArr(arr, N) << endl;
}