#include <iostream>
using namespace std;

void getPositiveAndNegativeCount(const int arr[], size_t size, int& countPositive, int& countNegative) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            countPositive++;
        }
        else {
            countNegative++;
        }
    }
}

//Задача 3: Да се напише функция getPositiveAndNegativeCount, която приема масив от цели числа, преброява броя на позитивни и отрицателни числа и ги сравнява.
int main() {
    constexpr int SIZE = 10;
    int arr[SIZE] = { -1,4 ,6,7,9,-4, -7,8 ,-9, 5 };
    int countPositive = 0;
    int countNegative = 0;
    getPositiveAndNegativeCount(arr, SIZE, countPositive, countNegative);
    cout << "positive: " << countPositive << endl;
    cout << "negative: " << countNegative << endl;

    if (countPositive > countNegative)
    {
        cout << "The number of positive integers is greater than the number of negative integers.";
    }
    else if (countNegative > countPositive)
    {
        cout << "The number of negative integers is greater than the number of positive integers.";
    }
    else 
    {
        cout << "The number of positive integers is equal to the number of negative integers.";
    }

}