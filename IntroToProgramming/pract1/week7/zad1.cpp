#include <iostream>
using namespace std;

void toBinary(int a, int arr[], size_t size) {
    int count = size - 1;
    while (a != 0 && count >= 0) {
        arr[count] = a % 2;
        a /= 2;
        count--;
    }
}

int main()
{
    int a;
    cin >> a;
    const int SIZE = 32;
    int arr[SIZE]{0};
    toBinary(a, arr, SIZE);
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];
    }
}