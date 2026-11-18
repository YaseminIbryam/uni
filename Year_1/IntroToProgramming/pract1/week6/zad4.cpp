#include <iostream>
using namespace std;


int sizeNum(int num) {

    int count = 0;
    while(num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
void getArr(int arr1[],int arr2[], size_t size, int& n, int& m) {
    for(int i = 0; i < size; i++) {
        arr1[i] = n % 10;
        n /= 10;
        arr2[i] = m % 10;
        m /= 10;
    }
    for(int i = 0; i < size/2; i++) {
        arr1[i] = 
    }
}
void swapIndexInArray(int& n, int& m, int& index) {

}
//Задача 4: Да се напише функция, която приема числа n , m и индекс на цифра k и разменя k-тите цифри на n и m.
int main() 
{
    constexpr int MAX_SIZE = 1024;
    int arr1[1024]{0};
    int arr2[1024]{0};
    int n;
    int m;
    cin >> n >> m;
    int size = sizeNum(n);
    getArr(arr1, arr2, size, n, m);



}