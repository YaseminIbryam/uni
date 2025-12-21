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
    //Задача 2: Напишете функция, която приема цяло число и връща броя на 1-ците в двоичния му запис.
    int a;
    cin >> a;
    const int SIZE = 32;
    int arr[SIZE]{0};
    toBinary(a, arr, SIZE);
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i]) {
            count++;
        }
    }
    cout << count;



// int countOnes(int a) {
//     int count = 0;
//     while (a) {
//         count += a & 1; // проверява последния бит
//         a >>= 1;        // мести всички битове надясно
//     }
//     return count;
// }

// int main() {
//     int a;
//     cin >> a;
//     cout << countOnes(a);
// }

// int countOnes(int a) {
//     int count = 0;
//     while (a != 0) {
//         if (a % 2 == 1) {  // проверява последния бит чрез остатък
//             count++;
//         }
//         a /= 2;  // мести към следващия бит
//     }
//     return count;
// }

// int main() {
//     int a;
//     cin >> a;
//     cout << countOnes(a);
// }
}