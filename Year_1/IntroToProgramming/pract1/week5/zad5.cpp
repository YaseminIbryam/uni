#include <iostream>
using namespace std;

//Задача 5: Напишете функция, която приема масив от цели положителни числа и позиция и премахва числото, което се намира на тази позиция и принтира "преобразувания" масив. (Задава му неутрална стойност -1). Индексирането започва от 0!
void removeElement(int arr[], size_t size, unsigned int position) {
    for(int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = -1;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    const int SIZE = 7;
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6};
    unsigned int position = 4;
    removeElement(arr, SIZE, position);
}