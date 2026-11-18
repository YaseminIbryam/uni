#include <iostream>
using namespace std;


//Задача 2: Да се напише функция, която приема квадратна матрица с n на n елемента отпечатва главния диагонал, след това и второстепенния.

void getMatrixDiagonals(const int arr[][100], size_t n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i][i] << " ";
    }
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i][i] << " ";
    }
}

int main() {
    int arr[][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = 3;
    getMatrixDiagonals(arr, n);
}