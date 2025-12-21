#include <iostream>
using namespace std;

bool isDigitIn(int digit, int num) {
    while (num != 0) {
        int lastDigit = num % 10;
        if (digit == lastDigit) {
            return true;
        }
        num /= 10;
    }
    return false;
}

bool isAnyDigitRepeated(int num) {
    bool isRepeated = false;
    do {
        int lastDigit = num % 10;
        num /= 10;
        if (isDigitIn(lastDigit, num)) {
            isRepeated = true;
        }
    } while(num != 0);
    
    return isRepeated;   
}


int main() {
    //Задача 1: Да се напише функиця, която приема n-цифрено число и проверява дали цифрите, които го съставят не се повтарят.
    int num;
    cin >> num;
    cout << !isAnyDigitRepeated(num);
}