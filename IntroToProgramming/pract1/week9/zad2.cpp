#include <iostream>
using namespace std;

int getBit(int N, int M) {
    return (N >> M) & 1;
}

int main() {
// Задача 2: Да се напише функция, която приема 2 цели числа N и M и връща бита на позиция M в числото N (отзад напред, започвайки от 0).
// Пример:
// Вход:
// 9 2
// Изход:
// 0 // 9 = 1001
int N;
int M;
cin >> N >> M;
cout << getBit(N, M);
}