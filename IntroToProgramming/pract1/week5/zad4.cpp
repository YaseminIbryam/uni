#include <iostream>
using namespace std;

//Задача 4: Да се напише функция, която приема масив от цели числа и проверява дали е сортиран възходящо.

bool isSorted(const int arr[], size_t size)
{
    int n = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < n)
        {
            return false;
        }
        n = arr[i];
    }
    return true;
}

int main()
{
    const int N = 4;
    int arr[4] = { 1, 2, 3, 4 };
    cout << isSorted(arr, N);
}