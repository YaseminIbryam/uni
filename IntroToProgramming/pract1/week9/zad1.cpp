#include <iostream>
using namespace std;

//Задача 1: Да се напише функция, която приема число k, между 0 и 31 и връща 2^k.
// Пример:
// Вход:
// 3
// Изход:
// 8
int powerOfTwo(int k) {
    return 1 << k;
}


int main() {
    int k;
    cin >> k;
    cout << powerOfTwo(k);
}