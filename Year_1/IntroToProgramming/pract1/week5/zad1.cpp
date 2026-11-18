#include <iostream>
using namespace std;


////Задача 1: Да се напише функция, която приема масив от цели числа и връща сумата на елементите му.
int sumArr(const int arr[], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    const int N = 4;
    int arr[N] = { 5, 7, 4, 9 };
    cout << sumArr(arr, N);
}
